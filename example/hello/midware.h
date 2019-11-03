#ifndef LZX_DLAGON_EXAMPLE_HELLO_MIDWARE_H_
#define LZX_DLAGON_EXAMPLE_HELLO_MIDWARE_H_

#include "dlagon/interface/midware.h"
#include "dlagon/interface/protocol/response.h"
#include "dlagon/http/body.h"

#include "dlagon/http/response.h"

using lzx::dlagon::http::HttpResponse;

class BasicMidware : public lzx::dlagon::interface::Midware{

   lzx::dlagon::interface::Midware::MidwareState Handle(const lzx::dlagon::interface::Request &req, lzx::dlagon::interface::Response &res) override{
      
      // res.SetBody(new lzx::dlagon::http::HttpResponseBody("HTTP/1.1 200 OK\r\nContent-Type : text/html\r\n\r\n<h1>Hello Dlagon!</h1>"));
      res = HttpResponse::HTTP_HTML_200.Clone();

      res.SetBody(new  lzx::dlagon::http::HttpResponseBody("<h1>Hello Dlagon!</h1>\r\n"));

      return MidwareState::kStop;
   }

};


#endif //LZX_DLAGON_EXAMPLE_HELLO_MIDWARE_H_