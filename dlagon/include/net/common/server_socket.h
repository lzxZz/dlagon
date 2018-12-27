// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.27

/*
   本文件声明服务端套接字,对普通套接字进行了封装,隐藏了Connect,Send,Receive方法
   使用组合实现,而非继承
*/
#ifndef DLAGON_NET_SERVER_SOCKET_H_
#define DLAGON_NET_SERVER_SOCKET_H_


#include <memory>
#include <tuple>


#include "net/common/client_socket.h"
#include "net/common/end_point.h"
#include "net/common/socket.h"

namespace dlagon{
namespace net{

   class ServerSocket{
   public:
      ServerSocket()
         : socket_(Socket::New()) {}
      void Bind(EndPoint endpoint);
      void Listen();
      void Listen(int queue_length);
      auto Accept()           
         -> std::tuple<std::shared_ptr<ClientSocket>, EndPoint>;

   private:
      Socket socket_;
   };



} //namespace net

} //namespace dlagon
#endif //DLAGON_NET_SERVER_SOCKET_H_