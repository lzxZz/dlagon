// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.11

/**
 * server/handler.h的实现
**/

#include "server/handler.h"

#include <assert.h>

#include <unistd.h>

#include <fstream>
#include <string>


#include "exception/exception.h"
#include "http/mime_type.h"

using std::ifstream;
using std::string;
using dlagon::http::HttpRequest;
using dlagon::http::HttpResponse;
using dlagon::http::HttpResponseHeader;
using dlagon::http::HttpResponseProtocol;

namespace dlagon
{
   // Hanlder的静态成员初始化
   string Handler::root_dir = "";

   HttpResponse Handler::GetFile(HttpRequest req){
      
      //若果没有初始化网站根目录则抛出异常.
      if (root_dir == ""){
         string info;
         info.append("没有设置网站的根目录");
         throw dlagon::exception::Exception{info};
      }
      string path = root_dir + req.Header().Path().ToString();
      string suffix = path.substr(path.find_last_of(".")+1);
      //判断文件存在
      if (access(path.c_str(),F_OK) == 0){
         HttpResponse res{HttpResponseHeader{http::HTTP_RESPONSE_PROTOCOL_200},""};
         res.Header().ArgTable().Set("Content-Type", http::MimeType::SuffixToMimeType(suffix));
      
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
      res.Header().ArgTable().Set("Content-Type","text/html");
      res.SetBody(u8"<header><meta charset=\"utf-8\"></header><h1>请求资源不存在</h1>");
   
      return res;

   }

   // 通过函数指针调用具体函数
   HttpResponse Handler::Excute(const HttpRequest &request){
      return worker_(request);
   }


} // dlagon

