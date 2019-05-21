/**
 * @file body.h
 * @author lzxZz (616281384@qq.com)
 * @brief 生命HTTP的请求体和响应体
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_HTTP_BODY_H_
#define LZX_DLAGON_HTTP_BODY_H_

#include "dlagon/interface/protocol/body.h"

namespace lzx::dlagon::http {

   /**
    * @brief Http响应消息体
    * 
    */
   class HttpResponseBody : public lzx::dlagon::interface::ProtocolBody{
   public:
      HttpResponseBody(const std::string &body) : body_(body) {}
      std::string ToString() override{
         return body_;
      }
   private:
      std::string body_;
   };

   /**
    * @brief Http请求响应体
    * 
    */
   class HttpRequestBody : public lzx::dlagon::interface::ProtocolBody{
      friend bool operator==(const HttpRequestBody &lhs, const HttpRequestBody &rhs);
      friend bool operator!=(const HttpRequestBody &lhs, const HttpRequestBody &rhs);
   public:
      HttpRequestBody(const std::string &body) : body_(body) {}
      std::string ToString() override{
         return body_;
      }
   private:
      std::string body_;
   };

}


#endif //LZX_DLAGON_HTTP_BODY_H_