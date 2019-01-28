// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.11

/*
   对http/http_client.h的实现
*/

#include "http/http_client.h"
#include "common/debug.h"

using std::string;
namespace dlagon{

namespace http{

   void HttpClient::Send(const string &str){
        DLAGON_CALL_DEBUG;
      this->socket_.Send(str);
   }

   void HttpClient::Send(const HttpResponse &response){
        DLAGON_CALL_DEBUG;
      Send(response.ToString());
   }

   string HttpClient::Recevie(){
        DLAGON_CALL_DEBUG;
      string str = this->socket_.Receive();
      // std::cout << str << std::endl;
      return str;
   }

   HttpRequest HttpClient::GetRequest(){
        DLAGON_CALL_DEBUG;
      string str = Recevie();
      // std::cout << str << std::endl;
      return HttpRequest::Parse(str);
   }


} //namespace http

} //namespace dlagon