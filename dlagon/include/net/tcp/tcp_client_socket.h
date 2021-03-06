// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.30

/*
   本文件声明Tcp客户端套接字,对Tcp套接字进行了封装,隐藏了Bind,Listen等方法
   使用组合实现,而非继承
*/

#ifndef DLAGON_NET_TCP_CLIENT_SOCKET_H_
#define DLAGON_NET_TCP_CLIENT_SOCKET_H_


#include <string>

#include "net/tcp/tcp_socket.h"

#include "net/common/end_point.h"

namespace dlagon{

namespace net{

namespace tcp{


      
      /**
       * 
       *    TCP客户端套接字, 使用组合实现
       * 
       *    只有Send,Recevive Connect三个函数使用.
       * 
      **/

      class TcpClientSocket{
      public:  
         TcpClientSocket(const int fd) 
            : socket_(fd) {}
            
         TcpClientSocket() 
            : socket_(TcpSocket{}) {}
         TcpClientSocket(const std::shared_ptr<const int> fdp)
            : socket_(fdp) {}

         TcpClientSocket(const Socket &sock)
            : socket_(sock.PointerFD()) {}
         TcpClientSocket(const Socket &&sock)
            : socket_(sock.PointerFD()) {}
         TcpClientSocket(const TcpClientSocket &sock)
            : socket_(sock.PointerFD()) {}
         TcpClientSocket(TcpClientSocket &&sock)
            : socket_(sock.PointerFD()) {}

         void Send(const std::string &str);

         void Send(const char* const str, const size_t len);

         auto Receive() 
            -> std::string;

         void Connect(const EndPoint &endpoint);
         const std::shared_ptr<const int> PointerFD() const{
            return socket_.PointerFD();
         }
         const int FD() const;

      private:
         TcpSocket socket_;
      };
} //namespace tcp

} //namespace net

} //namespace dlagon

#endif //DLAGON_NET_TCP_CLIENT_SOCKET_H_