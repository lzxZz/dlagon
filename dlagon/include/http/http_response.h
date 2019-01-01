// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.1

/*
   本文件声明HTTP响应,有响应头和响应体组成,
*/
#ifndef DLAGON_HTTP_RESPONSE_H_
#define DLAGON_HTTP_RESPONSE_H_

#include "http/header.h"

namespace dlagon{

namespace http{

   class HttpResponse{
   public:
      HttpResponse(HttpResponseHeader header, std::string body)
         : header_(header), body_(body) {}

      // 将HTTP响应转化为字符粗,通过HTTPClient发送
      std::string ToString() const;
      // 返回响应头
      const HttpResponseHeader Header() const;
      // 添加非常量的响应头,用于调用hashmap的成员方法
      HttpResponseHeader Header();
      const std::string        Body() const;
      void SetBody(std::string content){
         body_ = content;
      }
   private:
      HttpResponseHeader   header_;
      std::string          body_;
   };
}

} //namespace
#endif //DLAGON_HTTP_RESPONSE_H_