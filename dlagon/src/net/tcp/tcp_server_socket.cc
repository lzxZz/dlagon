// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.30

/*
   对net/tcp/tcp_server_socket.h的实现
*/

#include "net/tcp/tcp_server_socket.h"

#include "common/debug.h"
namespace dlagon{

namespace net{

namespace tcp{
   void TcpServerSocket::Bind(const int port){
        DLAGON_CALL_DEBUG;
      
      Bind(EndPoint{port});
   }
   void TcpServerSocket::Bind(const EndPoint &endpoint){
        DLAGON_CALL_DEBUG;
      this->socket_.Bind(endpoint);
   }

   void TcpServerSocket::Listen(){
        DLAGON_CALL_DEBUG;
      this->Listen(LISTENQ);
   }
   void TcpServerSocket::Listen(const int queue_length){
        DLAGON_CALL_DEBUG;
      this->socket_.Listen(queue_length);
   }

   auto TcpServerSocket::Accept() 
      -> std::tuple<TcpClientSocket, EndPoint>
   {
        DLAGON_CALL_DEBUG;
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