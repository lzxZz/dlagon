#include "server/handler.h"

#include <assert.h>

#include <unistd.h>

#include <fstream>
#include <string>

#include "exception/exception.h"
using std::ifstream;
using std::string;
using dlagon::http::HttpRequest;
using dlagon::http::HttpResponse;
using dlagon::http::HttpResponseHeader;
using dlagon::http::HttpResponseProtocol;

namespace dlagon
{
   string Handler::root_dir = "";

   HttpResponse Handler::GetFile(HttpRequest req){
      if (root_dir == ""){
         string info;
         info.append("没有设置网站的根目录");
         throw dlagon::exception::Exception{info};
      }
      string path = root_dir + req.Header().Path().ToString();

      //判断文件存在
      if (access(path.c_str(),F_OK) == 0){
         HttpResponse res{HttpResponseHeader{http::HTTP_RESPONSE_PROTOCOL_200},""};
         res.Header().ArgTable().emplace(std::make_pair("Content-Type","text/html"));

         string content;
         ifstream is;
         is.open(path);
         assert(is.is_open() == true);
         string line;
         while(getline(is, line)){
            content.append(line);
            content.append("\n");
         }
         res.SetBody(content);
         return res;

      }
      HttpResponse res{HttpResponseHeader{http::HTTP_RESPONSE_PROTOCOL_404},""};
      res.Header().ArgTable().emplace(std::make_pair("Content-Type","text/html"));
      res.SetBody("<h1>请求资源不存在</h1>");
   
      return res;

      


   }

   // 通过函数指针调用具体函数
   void Handler::Excute(HttpRequest request){
      worker_(request);
   }


} // dlagon

