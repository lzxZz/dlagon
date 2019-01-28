// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.4

/**
 * server/server.h的实现
**/

#include "server/server.h"

#include <cassert>

#include <thread>
#include <tuple>

#include "common/debug.h"
#include "net/common/end_point.h"
using std::string;
using std::tuple;
using std::thread;


using dlagon::http::HttpClient;
using dlagon::http::HttpServer;
using dlagon::net::EndPoint;
using dlagon::http::HttpRequest;
using dlagon::http::HttpResponse;
namespace dlagon
{
   void Worker(Server *server , HttpClient client){
        DLAGON_CALL_DEBUG;
      HttpRequest req =  client.GetRequest();
      
      Handler handler =  server->Route().Distribute(req.Header().Path());
      
      string sid =  req.Header().Cookies().Get("SID");
      
      // 有时候,会带有\r, 目前还没有比较好的结局方案
      if (sid.size() > 18){
         sid = sid.substr(0,18);
      }
      http::Session *session = server->sessions_.Get(sid); 
      if (sid == "" || session == nullptr){     // 如果当前会话ID不存在,或者不再会话列表中,那么就重新设置
         sid = server->sessions_.New(req);
         session = server->sessions_.Get(sid); 
      }
      
      
      
      session->AddHistorical(req); // 追加访问记录

      HttpResponse  res =  handler.Excute(req, *session); // 使用handler处理
      
      res.AddCookie(http::Cookie{"SID", sid});           // 刷新cookie
      client.Send(res.ToString());
   }

   void Server::Run(string root_dir, int port){
        DLAGON_CALL_DEBUG;
      // 必须设置正确的网站根目录
      Handler::root_dir = root_dir;
      
      server_.Bind(port);
      server_.Listen();
      using Result = tuple<HttpClient, EndPoint>;

      for (;;){

      
         Result result = server_.Accept();
         HttpClient client = std::get<0>(result);
   
   
         thread th(Worker, this, client);
         th.detach();
      }

   }

   Server &Server::SetRoute(dlagon::Route route){
        DLAGON_CALL_DEBUG;
      route_ = route;  
      return *this;
   }

   dlagon::Route Server::Route(){
        DLAGON_CALL_DEBUG;
      return route_;
   }
   
   
} // dlagon
