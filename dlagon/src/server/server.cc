// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.4

/**
 * server/server.h的实现
**/

#include "server/server.h"

#include <thread>
#include <tuple>

#include "net/common/end_point.h"
using std::string;
using std::tuple;
using std::thread;


using dlagon::http::HttpClient;
using dlagon::http::HttpServer;
using dlagon::net::EndPoint;
using dlagon::http::HttpRequest;
namespace dlagon
{
   void Worker(Server server , HttpClient client){
      HttpRequest req =  client.GetRequest();

      Handler handler =  server.Route().Distribute(req.Header().Path());
      string str = handler.Excute(req).ToString();
      client.Send(str);
   }

   void Server::Run(string root_dir, int port){
      // 必须设置正确的网站根目录
      Handler::root_dir = root_dir;
      
      server_.Bind(port);
      server_.Listen();
      using Result = tuple<HttpClient, EndPoint>;

      for (;;){

      
         Result result = server_.Accept();
         HttpClient client = std::get<0>(result);
   
   
         thread th(Worker, *this, client);
         th.detach();
      }

   }

   Server &Server::SetRoute(dlagon::Route route){
      route_ = route;
      return *this;
   }

   dlagon::Route Server::Route(){
      return route_;
   }
   
   
} // dlagon
