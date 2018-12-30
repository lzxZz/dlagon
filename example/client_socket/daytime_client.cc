// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.25

/*
   UNP一书中TCP时间获取客户端的ClientSocket封装版.
*/


#include "dlagon.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;



int main(){
   

   try
   {
      using namespace dlagon::net;
      using namespace dlagon::net::tcp;

      TcpClientSocket sock;
      
      sock.Connect(EndPoint{13});     // 时间服务器需要连接13端口号
      string content;
      while( (content =  sock.Receive()) != "")
      {
         cout << content << endl;
      }
      }
      catch(dlagon::exception::Exception &e)
      {
         cout << e.What() << endl;
      }
   
   return 0;
   
   
}