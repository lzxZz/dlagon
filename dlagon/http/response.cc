/**
 * @file response.cc
 * @author lzxZz (616281384@qq.com)
 * @brief HTTP响应
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "dlagon/http/response.h"

using std::string;

string hello_string =   "HTTP/1.1 200 OK\r\nContent-Type : text/html"
                        "\r\n\r\n<h1>Hello Dlagon!</h1>";

namespace lzx::dlagon::http{
   const string HttpResponse::ToString() const{
      string result;
      result += dynamic_cast<HttpResponseHead*>(head_)->ToString();
      result += argument_->ToString();
      result += "\r\n";
      result +=   dynamic_cast<HttpResponseBody*>(body_)->ToString();
      return result;
      
   }

   HttpResponse HttpResponse::HTTP_HTML_200 = HttpResponse(200, dynamic_cast<HttpArgument*>(HttpArgumentFactory::GetInstant()->FromString("Content-Type:text/html")) , "");
   HttpResponse HttpResponse::HTTP_HTML_404 = HttpResponse(404, dynamic_cast<HttpArgument*>(HttpArgumentFactory::GetInstant()->FromString("Content-Type:text/html")) , "");
}