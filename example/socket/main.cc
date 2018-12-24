#include "dlagon.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
int main(){
   int fd = socket(AF_INET, SOCK_STREAM, 0);
   dlagon::net::Socket sock{fd};
   dlagon::net::EndPoint endpoint{13};

   endpoint.IP("127.0.0.1");
   endpoint.Port(13);

   cout << endpoint.Debug();
   
   sock.Connect(endpoint);
   
   string content;
   while( (content =  sock.Receive()) != "")
   {
      cout << content << endl;
   }
}