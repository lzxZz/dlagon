#include "dlagon/web/server.h"
#include "dlagon/web/server_factory.h"

#include "dlagon/net/tcp/tcp_socket.h"
#include "dlagon/http/protocol_factory.h"

#include "midware.h"

#include <iostream>

using namespace lzx::dlagon::web;


using lzx::dlagon::http::HttpProtocolFactory;
using lzx::dlagon::net::tcp::TcpServerSocket;

using namespace std;

int main(){
   WebServerBuilder *server_builder = WebServerBuilder::GetInstant();
   // server_builder->Init();
   
   server_builder->SetProtocolFactory(HttpProtocolFactory::GetInstant());
   
   // server_builder->SetRoute(new BasicRoute());
   server_builder->SetMidware(new BasicMidware{});
   
   server_builder->SetServerSocket(new TcpServerSocket());
   
   WebServer *server = server_builder->GetWebServer();
   
   server->Run(8080);
   
}