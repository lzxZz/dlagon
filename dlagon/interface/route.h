#ifndef LZX_DLAGON_INTERFACE_ROUTE_H_
#define LZX_DLAGON_INTERFACE_ROUTE_H_

#include "dlagon/interface/handler.h"
#include "dlagon/interface/protocol/request.h"
namespace lzx::dlagon::interface{
   class IRoute{
   public:
      virtual IHandler *Route(const Request &req) = 0;
      virtual ~IRoute(){}
   };
}


#endif //LZX_DLAGON_INTERFACE_ROUTE_H_