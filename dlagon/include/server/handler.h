// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.4

/*
    本文件声明的Handler类,用于表示一个处理HTTP请求,并返回HTTP响应的函数指针持有者
    
*/


#ifndef DLAGON_SERVER_HANDLER_H_
#define DLAGON_SERVER_HANDLER_H_

#include <string>

#include "http/http_request.h"
#include "http/http_response.h"

namespace dlagon
{
    /**
    * Handler类,用于持有处理某些请求的的函数指针,和Path成对的出现在Route类中
    **/
   class Handler {
      
      
   public:
      // 定义处理函数指针类型别名
      using HandlerFunction = http::HttpResponse(*)(http::HttpRequest);
      
      Handler(HandlerFunction function = GetFile)
         : worker_(function) {}
      
      // 默认实现的处理函数
      static http::HttpResponse GetFile(http::HttpRequest req);
      static std::string root_dir;  //返回请求文件的相对根目录
      // 调用函数指针的函数
      http::HttpResponse Excute(http::HttpRequest req);
   private:
      HandlerFunction worker_;   // 具体将请求转化为响应的函数,必须使用构造函数进行初始化
      
   };
   
} // dlagon



#endif // DLAGON_SERVER_HANDLER_H_
