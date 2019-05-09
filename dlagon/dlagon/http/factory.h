#ifndef LZX_DLAGON_HTTP_FACOTRY_H_
#define LZX_DLAGON_HTTP_FACOTRY_H_

#include "dlagon/interface/factory.h"




namespace lzx::dlagon::http{
   class HttpProtocolFactory : public lzx::dlagon::interface::IProtocolObjectFactory{
      lzx::dlagon::interface::Request *RequestFromString(const std::string &str) override;
      lzx::dlagon::interface::Response *GetResponse();
   }


};

#endif //LZX_DLAGON_HTTP_FACOTRY_H_