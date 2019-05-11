#include "dlagon/web/server.h"
#include "dlagon/web/server_factory.h"

#include "dlagon/net/tcp/tcp_socket.h"
#include "dlagon/http/protocol_factory.h"

#include "route.h"

#include <iostream>

using namespace lzx::dlagon::web;


using lzx::dlagon::http::HttpProtocolFactory;
using lzx::dlagon::net::tcp::TcpServerSocket;

using namespace std;

int main(){
   WebServerBuilder *server_builder = WebServerBuilder::GetInstant();
   server_builder->Init();
   cout << "1" << endl;
   server_builder->SetProtocolFactory(HttpProtocolFactory::GetInstant());
   cout << "2" << endl;
   server_builder->SetRoute(new BasicRoute());
   cout << "3" << endl;
   server_builder->SetServerSocket(new TcpServerSocket());
   cout << "4" << endl;
   WebServer *server = server_builder->GetWebServer();
   cout << "5" << endl;
   server->Run(8080);
   cout << "6" << endl;
}