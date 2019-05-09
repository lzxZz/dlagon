#ifndef LZX_DLAGON_INTERFACE_FACTORY_H_
#define LZX_DLAGON_INTERFACE_FACTORY_H_

#include "dlagon/interface/request.h"
#include "dlagon/interface/response.h"

namespace lzx::dlagon::interface{
   // 请求和响应对象的抽象工厂
   class IProtocolObjectFactory{
   public:
      Request *RequestFromString(const std::string &str);
      Response *Response();
   };
}


#endif //LZX_DLAGON_INTERFACE_FACTORY_H_