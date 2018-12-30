// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.25

/*
   UNP一书中TCP时间获取客户端的Socket封装版.
*/


#include "dlagon.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

using namespace dlagon::net::tcp;
using namespace dlagon::net;

int main(){
   int fd = socket(AF_INET, SOCK_STREAM, 0);
   TcpSocket sock{fd};
   EndPoint endpoint{13};

   endpoint.IP("127.0.0.1");
   endpoint.Port(13);

   try
   {
      sock.Connect(endpoint);
   }
   catch(dlagon::exception::Exception &e)
   {
      cout << e.What() << endl;
   }
   
   
   string content;
   while( (content =  sock.Receive()) != "")
   {
      cout << content << endl;
   }

   return 0;
}