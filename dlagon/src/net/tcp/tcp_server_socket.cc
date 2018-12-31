// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.30

/*
   对net/tcp/tcp_server_socket.h的实现
*/

#include "net/tcp/tcp_server_socket.h"

namespace dlagon{

namespace net{

namespace tcp{

   void TcpServerSocket::Bind(EndPoint endpoint){
      this->socket_.Bind(endpoint);
   }

   void TcpServerSocket::Listen(){
      this->Listen(LISTENQ);
   }
   void TcpServerSocket::Listen(int queue_length){
      this->socket_.Listen(queue_length);
   }

   auto TcpServerSocket::Accept() 
      -> std::tuple<TcpClientSocket, EndPoint>
   {
      using Result = std::tuple<Socket, EndPoint>;
      Result result = this->socket_.Accept();
      using std::shared_ptr;
      Socket sock = std::get<0>(result);
      TcpClientSocket client{sock};
      
      EndPoint endpoint = std::get<1>(result);

      return std::make_tuple(client, endpoint);
      
   }

} //namespace tcp

} //namespace net

} //namespace dlagon