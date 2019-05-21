#include "dlagon/http/protocol_factory.h"

#include "dlagon/http/request.h"
#include "dlagon/http/response.h"

#include <boost/algorithm/string.hpp>
#include <vector>
#include <set>
using std::string;
using std::vector;
using std::set;

using lzx::dlagon::interface::Request;
using lzx::dlagon::interface::Response;
using lzx::dlagon::interface::IProtocolObjectFactory;

using boost::split;
using boost::is_any_of;

#include "iostream"
using std::cout;
using std::endl;

namespace lzx::dlagon::http{
   HttpProtocolFactory *HttpProtocolFactory::factory_ = nullptr;

   Request *HttpProtocolFactory::RequestFromString(const std::string &str) {
      std::string info = str;
      // boost::replace_all(info, '\r', "");
      vector<string> lines;
      split(lines, info, is_any_of("\n"));
      
      HttpRequestHead *head = HttpHeadFactory::GetInstant()->GetHttpRequestHead(lines[0]);
      
      size_t split_index;  // 请求参数和请求体空行分割线的索引

      for (size_t i = 1; i < lines.size(); i++){
         if (lines[i] == "" || lines[i] == "\r"){
            split_index = i;
         }
      }

      set<string> arg_content;
      for (size_t i = 1; i < split_index; i++){
         arg_content.emplace(lines[i]);
      }

      string body_content;
      if (split_index + 1 < lines.size()){
         for (size_t i = split_index + 1; i < lines.size(); i++){
            body_content += lines[i] + '\n';
         }
      }

      HttpRequest *req = new HttpRequest;
      
      HttpArgument *arg = dynamic_cast<HttpArgument*>(HttpArgumentFactory::GetInstant()->FromString(arg_content));
      // (req->head_) = dynamic_cast<lzx::dlagon::interface::ProtocolHead*>(head);
      req->head_ = head;
      req->body_ = new HttpRequestBody(body_content);
      req->argument_ = arg;
      return req;
   }

   Response *HttpProtocolFactory::GetResponse(){
      return new HttpResponse();
   }

   IProtocolObjectFactory *HttpProtocolFactory::GetInstant(){
      if (factory_ == nullptr){
         factory_  = new HttpProtocolFactory();
      }
      return factory_;
   }
}