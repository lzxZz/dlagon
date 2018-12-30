// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.26

/*
   简单的HTTP服务器
*/


#include "dlagon.h"

using namespace dlagon;
using namespace dlagon::net;
using namespace dlagon::net::tcp;

#include <iostream>
#include <tuple>
#include <memory>
#include <thread>
using namespace std;

void rw_socket(TcpClientSocket sock){
   cout << sock.Receive() << endl;
   
   string info = "HTTP/1.1 200 OK\r\nContent-Type : text/html\r\n\r\n<h1>Hello Wrold!</h1>";
   
         
   sock.Send(info);
         
   cout << "发送完成" << endl;
}

int main(){

   try
   {
      TcpServerSocket sock = TcpServerSocket();
      sock.Bind(8080);
      sock.Listen();
      for (;;){
         cout << "waiting ..." << endl;
         
         using Result =  std::tuple<TcpClientSocket, EndPoint>;
         Result result = sock.Accept();
         
         cout << get<1>(result).Debug() << endl;

         TcpClientSocket client = get<0>(result);

         
         
         

         cout << "客户端对应FD为:"<< client.FD() << endl;

         using std::thread;
         thread cth(rw_socket, client);
         cth.detach();
        
      }
         
      
   }
   catch(const dlagon::exception::Exception &e)
   {
      std::cerr << e.What() << '\n';
   }
   
   


   return 0;
}