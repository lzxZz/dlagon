/**
 * @file head.h
 * @author lzxZz (616281384@qq.com)
 * @brief 协议头
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_INTERFACE_PROTOCOL_H_
#define LZX_DLAGON_INTERFACE_PROTOCOL_H_

#include <string>

namespace lzx::dlagon::interface{
   class ProtocolHead{
      // 协议头的构造交给工厂
      virtual std::string ToString() = 0;
   };
}


#endif //LZX_DLAGON_INTERFACE_PROTOCOL_H_