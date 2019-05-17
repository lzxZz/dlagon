/**
 * @file body.h
 * @author lzxZz (616281384@qq.com)
 * @brief 协议消息体
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_INTERFACE_PROTOCOL_BODY_H_
#define LZX_DLAGON_INTERFACE_PROTOCOL_BODY_H_

#include <string>

namespace lzx::dlagon::interface{
   class ProtocolBody{
      virtual  std::string ToString()= 0;
   };

   
}


#endif //LZX_DLAGON_INTERFACE_PROTOCOL_BODY_H_