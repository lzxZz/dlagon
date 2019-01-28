// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.11

/*
   对`http/http_response.h`的实现
*/

#include "http/http_response.h"
#include <string>

#include "common/debug.h"

using std::string;
namespace dlagon{

namespace http{
   string HttpResponse::ToString() const{
        DLAGON_CALL_DEBUG;
      // string info;
      // info.append(Header().ToString());
      // info.append(Body());
      return Header().ToString() + Body();
   }

   void HttpResponse::SetBody(const string &content){
        DLAGON_CALL_DEBUG;
      body_ = content;
   }

   void HttpResponse::AddCookie(const Cookie &cookie){
        DLAGON_CALL_DEBUG;
      header_.AddCookie(cookie);
   }
   void HttpResponse::ClearCookie(){
        DLAGON_CALL_DEBUG;
      header_.ClearCookie();
   }
   
   const HttpResponseHeader &HttpResponse::Header() const{
        DLAGON_CALL_DEBUG;
      return header_;
   }
   HttpResponseHeader &HttpResponse::Header() {
        DLAGON_CALL_DEBUG;
      return header_;
   }

   const string HttpResponse::Body() const{
        DLAGON_CALL_DEBUG;
      return body_;
   }
} //namespace http
} //namespace dlagon