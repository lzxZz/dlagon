// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.27

#include "net/tcp/tcp_client_socket.h"

using std::string;

namespace dlagon{

namespace net{

namespace tcp{
   void  TcpClientSocket::Send(const std::string &str){
      this->socket_.Send(str);
   }
   void TcpClientSocket::Send(const char *str, size_t len){
      this->socket_.Send(str, len);
   }

   std::string TcpClientSocket::Receive(){   
      return this->socket_.Receive();
   }

   void TcpClientSocket::Connect(EndPoint endpoint){
      this->socket_.Connect(endpoint);
   }    

   const int TcpClientSocket::FD() const{
      return this->socket_.FD();
   }
   
} //namespace tcp

} //namespace net

} //namespace dlagon