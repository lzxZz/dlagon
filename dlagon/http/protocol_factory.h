/**
 * @file protocol_factory.h
 * @author lzxZz (616281384@qq.com)
 * @brief HTTP请求和响应工厂
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_HTTP_FACOTRY_H_
#define LZX_DLAGON_HTTP_FACOTRY_H_

#include "dlagon/interface/protocol/factory.h"

namespace lzx::dlagon::http{

   /**
    * @brief HTTP协议构造工厂
    * 
    */
   class HttpProtocolFactory : public lzx::dlagon::interface::IProtocolObjectFactory{
   public:
      lzx::dlagon::interface::Request *RequestFromString(const std::string &str) override;
      lzx::dlagon::interface::Response *GetResponse();
      static lzx::dlagon::interface::IProtocolObjectFactory *GetInstant();
   private:
      HttpProtocolFactory(){}
      static HttpProtocolFactory *factory_;
   };
}

#endif //LZX_DLAGON_HTTP_FACOTRY_H_