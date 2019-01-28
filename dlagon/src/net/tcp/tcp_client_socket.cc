// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.30

// 对net/tcp/tcp_client_socket.h的实现

#include "net/tcp/tcp_client_socket.h"
#include "common/debug.h"
using std::string;

namespace dlagon{

namespace net{

namespace tcp{
   void  TcpClientSocket::Send(const std::string &str){
        DLAGON_CALL_DEBUG;
      this->socket_.Send(str);
   }
   void TcpClientSocket::Send(const char* const str,const size_t len){
        DLAGON_CALL_DEBUG;
      this->socket_.Send(str, len);
   }

   std::string TcpClientSocket::Receive(){   
        DLAGON_CALL_DEBUG;
      return this->socket_.Receive();
   }

   void TcpClientSocket::Connect(const EndPoint &endpoint){
        DLAGON_CALL_DEBUG;
      this->socket_.Connect(endpoint);
   }    

   const int TcpClientSocket::FD() const{
        DLAGON_CALL_DEBUG;
      return this->socket_.FD();
   }
   
} //namespace tcp

} //namespace net

} //namespace dlagon