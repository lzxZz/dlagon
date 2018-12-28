// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.27

/*
   本文件声明客户端套接字,对普通套接字进行了封装,隐藏了Bind,Listen等方法
   使用组合实现,而非继承
*/

#ifndef DLAGON_NET_CLIENT_SOCKET_H_
#define DLAGON_NET_CLIENT_SOCKET_H_


#include <string>

#include "net/common/socket.h"

#include "net/common/end_point.h"

namespace dlagon{
   namespace net{


      
      /**
       * 
       *    客户端套接字, 使用组合实现
       * 
       *    只有Send,Recevive Connect三个函数使用.
       * 
      **/

      class ClientSocket{
      public:  
         ClientSocket(int fd) 
            : socket_(fd) {}
            
         ClientSocket() 
            : socket_(Socket::New()) {}

         ClientSocket(Socket &sock)
            : socket_(sock.PointerFD()) {}

         void Send(const std::string &str);

         void Send(const char *str, size_t len);

         auto Receive() 
            -> std::string;

         void Connect(EndPoint endpoint);

      private:
         Socket socket_;
      };
   
   } //namespace net
} //namespace dlagon

#endif //DLAGON_NET_CLIENT_SOCKET_H_