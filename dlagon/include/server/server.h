// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.4

/**
 * 本文件声明的Server类, 表示一个web服务的实例.  
**/
#ifndef DLAGON_SERVER_SERVER_H_
#define DLAGON_SERVER_SERVER_H_

#include <vector>

#include "http/http_server.h"
#include "server/handler.h"
#include "server/route.h"


namespace dlagon{
  

   
   /*
   *  WEB服务的核心组件,
   */
   class Server{
   // using Handler = http::HttpResponse(*)(http::HttpRequest);
   // using Route = Handler(*)(http::HttpRequest);
   public:
      Server() = default;
      Server(dlagon::Route route)
         : route_(route) {}

      void Run(std::string root_dir, int port = 8080);  //默认运行于8080端口
      dlagon::Route Route();
      Server &SetRoute(dlagon::Route route);
   private:
      http::HttpServer server_;
      dlagon::Route route_;
   };
}

#endif //DLAGON_SERVER_SERVER_H_
