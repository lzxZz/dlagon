// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.27

/*
   UNP一书中TCP时间获取服务端的ServerSocket封装版.
*/

#include "dlagon.h"

#include <time.h>
#include <stdio.h>

#include <string>
#include <tuple>
#include <iostream>
#include <memory>
using std::tuple;
using std::string;
using std::cout;
using std::endl;

using namespace dlagon;
using namespace dlagon::net;
using namespace dlagon::net::tcp;

int main(){

    
   try
   {
      TcpServerSocket sock;
      sock.Bind(13);
      sock.Listen();
      for (;;){
         cout << "waiting ..." << endl;
         using std::shared_ptr;
         using Result = tuple<TcpClientSocket, EndPoint>;
         
         Result result = sock.Accept();
         
         cout << std::get<1>(result).Debug() << endl;

         TcpClientSocket client = std::get<0>(result);

         

         // cout << "客户端对应套接字为:"<< client->FD() << endl;

         time_t ticks = time(NULL);
         char buf[4096];
         snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&ticks));
         string info;
         info.append(buf, strlen(buf));
         client.Send(info);
      
      }
   }
   catch(const dlagon::exception::Exception &e)
   {
      std::cerr << e.What() << '\n';
   }
   
   

   return 0;

}