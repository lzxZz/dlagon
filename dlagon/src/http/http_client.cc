// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.11

/*
   对http/http_client.h的实现
*/

#include "http/http_client.h"

using std::string;
namespace dlagon{

namespace http{

   void HttpClient::Send(const string &str){
      this->socket_.Send(str);
   }

   void HttpClient::Send(const HttpResponse &response){
      Send(response.ToString());
   }

   string HttpClient::Recevie(){
      string str = this->socket_.Receive();
      // std::cout << str << std::endl;
      return str;
   }

   HttpRequest HttpClient::GetRequest(){
      string str = Recevie();
      std::cout << str << std::endl;
      return HttpRequest::Parse(str);
   }


} //namespace http

} //namespace dlagon