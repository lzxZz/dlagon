/**
 * @file argument.h
 * @author lzxZz (616281384@qq.com)
 * @brief 参数的抽象
 * @version 0.1
 * @date 2019-05-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_INTERFACE_PROTOCOL_ARGUMENT_H_
#define LZX_DLAGON_INTERFACE_PROTOCOL_ARGUMENT_H_

#include <string>

namespace lzx::dlagon::interface{
   
   class Argument{
   public:
      virtual std::string ToString()  = 0;
   };
   class ArgumentFactory{
   public:
      virtual Argument *FromString(const std::string &str) = 0;
   };
}


#endif //LZX_DLAGON_INTERFACE_PROTOCOL_ARGUMENT_H_