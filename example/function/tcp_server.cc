#include "dlagon/net/tcp/tcp_socket.h"

#include <iostream>

using namespace std;

using namespace lzx::dlagon::net::tcp;

int main(){
   TcpServerSocket server{};
   server.Bind(8080);
   server.Listen(1024);

   for (;;){
      auto client = server.Accept();
      string result = client->Receviced();
      cout << result << endl;
      client->Send(result);
      delete client;

   }

   return 0;
}