#include "dlagon/web/server.h"
#include "dlagon/web/server_factory.h"

#include "dlagon/net/tcp/tcp_socket.h"
#include "dlagon/http/protocol_factory.h"

#include "dlagon/http/midware/static/static_file.h"
#include "dlagon/http/midware/route/basic_route.h"
#include "dlagon/http/midware/route/handler.h"
#include <iostream>

#include "example/todo/login.h"

using namespace lzx::dlagon::web;


using lzx::dlagon::http::HttpProtocolFactory;
using lzx::dlagon::net::tcp::TcpServerSocket;
using lzx::dlagon::http::midware::StaticFileMidWare;
using namespace std;


using namespace lzx::dlagon::http;
using namespace lzx::dlagon::http::midware;

// void Login(const HttpRequest &req, HttpResponse &res){
//    req.Head().Type()
//       cout << "---" << endl;
//       cout << req.UrlArgument().ToString() << endl;
//       cout << "---" << endl;

//    cout << "+++" << endl;
//    cout << req.PostArgument().ToString() << endl;
//    cout << "+++" << endl;
      
   
//    res = HttpResponse::HTTP_HTML_200.Clone();
//    res.Argument().Set("CharSet", "UTF-8");
//    res.Argument().Set("Content-Type", "text/plain");
   
//    string content = "<meta charset=\"utf-8\">登录注册请求处理<br>";

//    res.SetBody(content);
// }

int main(){
   lzx::dlagon::example::todo::Init("");

   WebServerBuilder *server_builder = WebServerBuilder::GetInstant();
   // server_builder->Init();
   
   server_builder->SetProtocolFactory(HttpProtocolFactory::GetInstant());
   
   BasicRoute *route = new BasicRoute();
   route->SetNext(new StaticFileMidWare("/home/lzx/dlagon/example/todo/static"));

   route->Regiest("/Login.dlagon",Handler{lzx::dlagon::example::todo::Login});

   server_builder->SetMidware(route);
   
   server_builder->SetServerSocket(new TcpServerSocket());
   
   WebServer *server = server_builder->GetWebServer();
   
   server->Run(8080);
   
}