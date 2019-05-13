#ifndef LZX_DLAGON_HTTP_FACOTRY_H_
#define LZX_DLAGON_HTTP_FACOTRY_H_

#include "dlagon/interface/protocol/factory.h"




namespace lzx::dlagon::http{
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