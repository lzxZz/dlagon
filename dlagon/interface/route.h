#ifndef LZX_DLAGON_INTERFACE_ROUTE_H_
#define LZX_DLAGON_INTERFACE_ROUTE_H_

#include "dlagon/interface/handler.h"
#include "dlagon/interface/request.h"
namespace lzx::dlagon::interface{
   class IRoute{
   public:
      virtual IHandler *operator()(const Request &req);
   };
}


#endif //LZX_DLAGON_INTERFACE_ROUTE_H_