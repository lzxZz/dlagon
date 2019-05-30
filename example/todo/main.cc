#include "dlagon/web/server.h"
#include "dlagon/web/server_factory.h"

#include "dlagon/net/tcp/tcp_socket.h"
#include "dlagon/http/protocol_factory.h"

#include "dlagon/http/midware/static_file.h"

#include <iostream>

using namespace lzx::dlagon::web;


using lzx::dlagon::http::HttpProtocolFactory;
using lzx::dlagon::net::tcp::TcpServerSocket;
using lzx::dlagon::http::midware::StaticFileMidWare;
using namespace std;

int main(){
   WebServerBuilder *server_builder = WebServerBuilder::GetInstant();
   // server_builder->Init();
   
   server_builder->SetProtocolFactory(HttpProtocolFactory::GetInstant());
   
   server_builder->SetMidware(new StaticFileMidWare("/home/lzx/dlagon/example/todo/static"));
   
   server_builder->SetServerSocket(new TcpServerSocket());
   
   WebServer *server = server_builder->GetWebServer();
   
   server->Run(8080);
   
}