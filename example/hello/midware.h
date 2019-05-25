#ifndef LZX_DLAGON_EXAMPLE_HELLO_MIDWARE_H_
#define LZX_DLAGON_EXAMPLE_HELLO_MIDWARE_H_

#include "dlagon/interface/midware.h"
#include "dlagon/interface/protocol/response.h"
#include "dlagon/http/body.h"


class BasicMidware : public lzx::dlagon::interface::Midware{

   lzx::dlagon::interface::Midware::MidwareState Handler(const lzx::dlagon::interface::Request &req, lzx::dlagon::interface::Response &res) override{
      
      res.SetBody(new lzx::dlagon::http::HttpResponseBody("HTTP/1.1 200 OK\r\nContent-Type : text/html\r\n\r\n<h1>Hello Dlagon!</h1>"));
      return MidwareState::kStop;
   }

};


#endif //LZX_DLAGON_EXAMPLE_HELLO_MIDWARE_H_