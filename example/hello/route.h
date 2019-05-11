#ifndef LZX_DLAGON_EXAMPLE_HELLO_ROUTE_H_
#define LZX_DLAGON_EXAMPLE_HELLO_ROUTE_H_

#include "dlagon/interface/route.h"
#include "dlagon/interface/request.h"

class BasicRoute : public lzx::dlagon::interface::IRoute{
public:
   lzx::dlagon::interface::IHandler *Route(const lzx::dlagon::interface::Request &req) override;
};

#endif //LZX_DLAGON_EXAMPLE_HELLO_ROUTE_H_