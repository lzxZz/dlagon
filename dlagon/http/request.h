/**
 * @file request.h
 * @author lzxZz (616281384@qq.com)
 * @brief HTTP请求头
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_HTTP_REQUEST_H_
#define LZX_DLAGON_HTTP_REQUEST_H_

#include "dlagon/interface/protocol/request.h"

#include "dlagon/http/argument.h"
#include "dlagon/http/head.h"
#include "dlagon/http/body.h"
namespace lzx::dlagon::http{
   class HttpRequest : public lzx::dlagon::interface::Request{
   friend bool operator==(const HttpRequest &lhs, const HttpRequest &rhs);
   friend bool operator!=(const HttpRequest &lhs, const HttpRequest &rhs);
   friend class HttpProtocolFactory;
   public:
      HttpRequest()
         
      {
         head_ = HttpHeadFactory::GetInstant()->GetHttpRequestHead("GET /index.html HTTP/1.1");
         body_ = new HttpRequestBody("");
         argument_ = new HttpArgument();
      }
   private:
      HttpArgument *argument_;
   } ;
}

#endif // LZX_DLAGON_HTTP_REQUEST_H_