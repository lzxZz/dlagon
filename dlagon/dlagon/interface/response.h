#ifndef LZX_DLAGON_INTERFACE_RESPONSE_H_
#define LZX_DLAGON_INTERFACE_RESPONSE_H_

#include <string>

namespace lzx::dlagon::interface{
class Response{
   public:
      virtual const std::string ToString() const = 0;
      virtual ~Response(){}
   };
}


#endif //LZX_DLAGON_INTERFACE_RESPONSE_H_