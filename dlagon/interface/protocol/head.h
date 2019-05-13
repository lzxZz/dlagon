#ifndef LZX_DLAGON_INTERFACE_PROTOCOL_H_
#define LZX_DLAGON_INTERFACE_PROTOCOL_H_

#include <string>

namespace lzx::dlagon::interface{
   class ProtocolHead{
      virtual ProtocolHead *FromString() = 0;
      virtual std::string ToString() = 0;
   };
}


#endif //LZX_DLAGON_INTERFACE_PROTOCOL_H_