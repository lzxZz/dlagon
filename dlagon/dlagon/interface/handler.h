#ifndef LZX_DLAGON_SERVER_HANDLER_H_
#define LZX_DLAGON_SERVER_HANDLER_H_

#include "dlagon/interface/request.h"
#include "dlagon/interface/response.h"

namespace lzx::dlagon::interface{

class IHandler{
   public:
      virtual void Handle(Request &req, Response &res) = 0;
   };

}

#endif //LZX_DLAGON_SERVER_HANDLER_H_