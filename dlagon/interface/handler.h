#ifndef LZX_DLAGON_SERVER_HANDLER_H_
#define LZX_DLAGON_SERVER_HANDLER_H_

#include "dlagon/interface/protocol/request.h"
#include "dlagon/interface/protocol/response.h"

namespace lzx::dlagon::interface{

class IHandler{
   public:
      virtual void Handle(Request &req, Response &res) = 0;
      virtual ~IHandler(){}
   };

}

#endif //LZX_DLAGON_SERVER_HANDLER_H_