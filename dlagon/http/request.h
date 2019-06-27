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
#include "dlagon/http/body.h"
#include "dlagon/http/head.h"

namespace lzx::dlagon::http{

   class HttpRequest : public lzx::dlagon::interface::Request{
   friend bool operator==(const HttpRequest &lhs, const HttpRequest &rhs);
   friend bool operator!=(const HttpRequest &lhs, const HttpRequest &rhs);
   friend class HttpProtocolFactory;
   public:
      HttpRequest(){ // 只有构造完成之后才能访问超类中的保护成员, 因此不能使用列表初始化
         head_ = HttpHeadFactory::GetInstant()->GetHttpRequestHead("GET /index.html HTTP/1.1");
         body_ = new HttpRequestBody("");
         argument_ = new HttpArgument();
      }
      const HttpArgument GetCookies() const{
         return *cookie_;
      }
      HttpArgument &Argument(){
         return *(dynamic_cast<HttpArgument*>(argument_));
      }
      const HttpArgument &UrlArgument() const{
         return *url_argument_;
      }
      const HttpArgument &PostArgument() const{
         return *post_argument_;
      }
      const HttpRequestHead &Head() const{
         return dynamic_cast<HttpRequestHead&>(*head_);
      }
   private:
      HttpArgument *url_argument_;
      HttpArgument *post_argument_;
      HttpArgument *cookie_;
   } ;
}

#endif // LZX_DLAGON_HTTP_REQUEST_H_