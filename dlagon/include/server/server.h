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
      void Run(std::string root_dir, int port = 8080);  //默认运行于8080端口
      dlagon::Route Route();
      Server &SetRoute(dlagon::Route route);
   private:
      // static void Worker(http::HttpClient client);
      http::HttpServer server_;
      dlagon::Route route_;
   };
}

#endif //DLAGON_SERVER_SERVER_H_
