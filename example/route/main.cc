#include "dlagon/web/server.h"
#include "dlagon/web/server_factory.h"

#include "dlagon/net/tcp/tcp_socket.h"
#include "dlagon/http/protocol_factory.h"


#include <iostream>

#include "dlagon/http/midware/route/basic_route.h"
#include "dlagon/http/midware/route/handler.h"

using namespace lzx::dlagon::web;


using lzx::dlagon::http::HttpProtocolFactory;
using lzx::dlagon::net::tcp::TcpServerSocket;

using namespace lzx::dlagon::http::midware;
using namespace lzx::dlagon::http;
using namespace std;


void NotFount(const HttpRequest &req, HttpResponse &res){
    res = HttpResponse::HTTP_HTML_404.Clone();
    res.SetBody("<h1>Not found</h1>");
}
void Login(const HttpRequest &req, HttpResponse &res){
    res = HttpResponse::HTTP_HTML_200.Clone();
    res.SetBody("<h1>Login</h1>");
}

int main(){
   WebServerBuilder *server_builder = WebServerBuilder::GetInstant();
   // server_builder->Init();
   
   server_builder->SetProtocolFactory(HttpProtocolFactory::GetInstant());
   
   // server_builder->SetRoute(new BasicRoute());

   BasicRoute *route = new BasicRoute{new Handler(NotFount)};
   route->Regiest("/login.html", Handler{Login});

   server_builder->SetMidware(route);
   
   server_builder->SetServerSocket(new TcpServerSocket());
   
   WebServer *server = server_builder->GetWebServer();
   
   server->Run(8080);
    
}