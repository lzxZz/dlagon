// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.11

/*
   本文件声明HTTP响应,有响应头和响应体组成,
*/
#ifndef DLAGON_HTTP_RESPONSE_H_
#define DLAGON_HTTP_RESPONSE_H_

#include <vector>

#include "http/header.h"
#include "http/cookie.h"


namespace dlagon{

namespace http{

   class HttpResponse{
   public:
      HttpResponse(const HttpResponseHeader &header, const std::string &body)
         : header_(header), body_(body) {
            Header().ArgTable().Set("Content-Type","text/html");
      }

      // 将HTTP响应转化为字符粗,通过HTTPClient发送
      std::string ToString() const;
      // 返回响应头
      const HttpResponseHeader &Header() const;

      // 添加非常量的响应头,用于调用hashmap的成员方法
      HttpResponseHeader &Header();
      const std::string        Body() const;
      void SetBody(const std::string &content);

      void AddCookie(const Cookie &cookie);
      void ClearCookie();
   private:
      HttpResponseHeader   header_;
      std::vector<Cookie>  cookies_;
      std::string          body_;
   };
}

} //namespace
#endif //DLAGON_HTTP_RESPONSE_H_