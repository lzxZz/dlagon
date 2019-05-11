#include "dlagon/http/response.h"

using std::string;

string hello_string =   "HTTP/1.1 200 OK\r\nContent-Type : text/html"
                        "\r\n\r\n<h1>Hello Dlagon!</h1>";

namespace lzx::dlagon::http{
   const string HttpResponse::ToString() const{
      return hello_string;
   }
}