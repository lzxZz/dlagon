// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.11

/*
   对`http/http_response.h`的实现
*/

#include "http/http_response.h"
#include <string>
using std::string;
namespace dlagon{

namespace http{
   string HttpResponse::ToString() const{
      // string info;
      // info.append(Header().ToString());
      // info.append(Body());
      return Header().ToString() + Body();
   }

   
   const HttpResponseHeader &HttpResponse::Header() const{
      return header_;
   }
   HttpResponseHeader &HttpResponse::Header() {
      return header_;
   }

   const string HttpResponse::Body() const{
      return body_;
   }
} //namespace http
} //namespace dlagon