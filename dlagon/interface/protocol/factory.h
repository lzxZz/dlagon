/**
 * @file factory.h
 * @author lzxZz (616281384@qq.com)
 * @brief 协议构造工厂
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_INTERFACE_FACTORY_H_
#define LZX_DLAGON_INTERFACE_FACTORY_H_

#include "dlagon/interface/protocol/request.h"
#include "dlagon/interface/protocol/response.h"

namespace lzx::dlagon::interface{
   // 请求和响应对象的抽象工厂
   class IProtocolObjectFactory{
   public:
      virtual Request *RequestFromString(const std::string &str) = 0;
      virtual Response *GetResponse() = 0;
      // virtual IProtocolObjectFactory *GetInstant();
      virtual ~IProtocolObjectFactory(){}
   };
}


#endif //LZX_DLAGON_INTERFACE_FACTORY_H_