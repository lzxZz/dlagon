// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.24

/*
   本文件声明客户端套接字,对普通套接字进行了封装,隐藏了Bind,Listen等方法
   使用组合实现,而非继承
*/

#ifndef DLAGON_NET_CLIENT_SOCKET_H_
#define DLAGON_NET_CLIENT_SOCKET_H_


#include "net/common/socket.h"

namespace dlagon{
   namespace net{


      
      /**
       * 
       *    客户端套接字, 使用组合实现
       * 
       *    只有Send,Recevive Connect三个函数使用.
       * 
      **/

      class ClientScoekt{
         ClientScoekt(int fd) 
         : socket_(fd) {}
         void Send();
         void Recevive();
         void Connect();
      private:
         dlagon::net::Socket socket_;
      };
   
   } //namespace net
} //namespace dlagon

#endif //DLAGON_NET_CLIENT_SOCKET_H_