#ifndef LZX_DLAGON_INTERFACE_PROTOCOL_BODY_H_
#define LZX_DLAGON_INTERFACE_PROTOCOL_BODY_H_

#include <string>

namespace lzx::dlagon::interface{
   class ProtocolBody{
      virtual  std::string ToString()= 0;
   };

   
}


#endif //LZX_DLAGON_INTERFACE_PROTOCOL_BODY_H_