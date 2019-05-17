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