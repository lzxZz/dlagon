// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.27

/*
   本文件声明服务端套接字,对普通套接字进行了封装,隐藏了Connect,Send,Receive方法
   使用组合实现,而非继承
*/

#include "net/common/server_socket.h"

namespace dlagon{

namespace net{
   void ServerSocket::Bind(EndPoint endpoint){
      this->socket_.Bind(endpoint);
   }

   void ServerSocket::Listen(){
      this->Listen(LISTENQ);
   }
   void ServerSocket::Listen(int queue_length){
      this->socket_.Listen(queue_length);
   }

   auto ServerSocket::Accept() 
      -> std::tuple<ClientSocket, EndPoint>
   {
      using Result = std::tuple<Socket, EndPoint>;
      Result result = this->socket_.Accept();
      using std::shared_ptr;
      Socket sock = std::get<0>(result);
      ClientSocket client{sock};
      
      EndPoint endpoint = std::get<1>(result);

      return std::make_tuple(client, endpoint);
      
   }


} //namespace net

} //namespace dlagon