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
   namespace {
      void Trim(string &s){
 
         if( !s.empty() ){
            s.erase(0,s.find_first_not_of(" "));
            s.erase(s.find_last_not_of(" ") + 1);
         }
 
      }
   }


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
            // cout << i << endl;
         }
      }

         
      set<string> arg_content;
      string cookie_content;
      for (size_t i = 1; i < split_index; i++){
         // cout << lines[i] << endl;


         
         if (lines[i].size() > 6 && lines[i].substr(0, 6) == "Cookie"){
            cookie_content = lines[i];
         }{
            arg_content.emplace(lines[i]);
         }
         
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
      HttpArgument *cookie = dynamic_cast<HttpArgument*>(HttpArgumentFactory::GetInstant()->FromString(""));

      cookie_content = cookie_content.substr(cookie_content.find(":")+1);
      set<string> cookies;
      split(cookies, cookie_content, is_any_of(";"));
      for (auto cookie_str : cookies){
         Trim(cookie_str);
         string key , value;
         key = cookie_str.substr(0, cookie_str.find("="));
         value = cookie_str.substr(cookie_str.find("=") + 1);
         cookie->args_.emplace(std::make_pair(key, value));

      }

      req->head_ = head;
      req->body_ = new HttpRequestBody(body_content);
      req->argument_ = arg;
      req->cookie_ = cookie;
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