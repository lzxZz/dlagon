#include "route.h"

#include "dlagon/interface/route.h"
#include "dlagon/interface/request.h"
#include "dlagon/interface/response.h"

using lzx::dlagon::interface::IRoute;
using lzx::dlagon::interface::IHandler;
using lzx::dlagon::interface::Request;
using lzx::dlagon::interface::Response;

class BaiscHandler : public IHandler{
   void Handle(Request &req, Response &res) override{
      res.SetBody("HTTP/1.1 200 OK\r\nContent-Type : text/html\r\n\r\n<h1>Hello Dlagon!</h1>");

   }
};

IHandler *BasicRoute::Route(const Request &req){
   return new BaiscHandler();
}
