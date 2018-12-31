#include "http/http_client.h"

using std::string;
namespace dlagon{

namespace http{

   void HttpClient::Send(const string &str){
      this->socket_.Send(str);
   }

   void HttpClient::Send(const HttpResponse response){
      Send(response.ToString());
   }

   string HttpClient::Recevie(){
      return this->socket_.Receive();
   }

   HttpRequest HttpClient::GetRequest(){
      return HttpRequest::Parse(Recevie());
   }


} //namespace http

} //namespace dlagon