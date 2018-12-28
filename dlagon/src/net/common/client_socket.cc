// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.27

#include "net/common/client_socket.h"

using std::string;

namespace dlagon{

namespace net{
   
   void  ClientSocket::Send(const std::string &str){
      this->socket_.Send(str);
   }
   void ClientSocket::Send(const char *str, size_t len){
      this->socket_.Send(str, len);
   }

   std::string ClientSocket::Receive(){   
      return this->socket_.Receive();
   }

   void ClientSocket::Connect(EndPoint endpoint){
      this->socket_.Connect(endpoint);
   }           
   

} //namespace net

} //namespace dlagon