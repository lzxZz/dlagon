// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.30

/*
   本文件声明TCP服务端套接字,对TCP套接字进行了封装,隐藏了Connect,Send,Receive方法
   使用组合实现,而非继承
*/
#ifndef DLAGON_NET_TCP_SERVER_SOCKET_H_
#define DLAGON_NET_TCP_SERVER_SOCKET_H_


#include <memory>
#include <tuple>


#include "net/tcp/tcp_client_socket.h"
#include "net/common/end_point.h"
#include "net/common/socket.h"

namespace dlagon{
namespace net{
namespace tcp{

   /***
    *
    *    TCP服务端套接字, 使用组合实现
    * 
    *    只有Bind, Listen, Accept三个函数使用
    * 
    **/
   class TcpServerSocket{
   public:
      TcpServerSocket()
         : socket_(Socket::New()) {}
      void Bind(int port);
      void Bind(EndPoint endpoint);
      void Listen(); //使用1024作为默认的监听队列长度
      void Listen(int queue_length);
      auto Accept()           
         -> std::tuple<TcpClientSocket, EndPoint>;

   private:
      TcpSocket socket_;
   };


} //namespace tcp

} //namespace net

} //namespace dlagon
#endif //DLAGON_NET_TCP_SERVER_SOCKET_H_