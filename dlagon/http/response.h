#ifndef LZX_DLAGON_HTTP_RESPONSE_H_
#define LZX_DLAGON_HTTP_RESPONSE_H_
/**
 * @file response.h
 * @author lzxZz (616281384@qq.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "dlagon/interface/protocol/response.h"

#include <string>
#include <set>

#include "dlagon/http/body.h"
#include "dlagon/http/argument.h"
#include "dlagon/http/cookie.h"
#include "dlagon/http/head.h"
namespace lzx::dlagon::http{
   enum class MimeType{
      kHtml,
      kCss,
      kJs,
      kPng,
      kGif,
   };

   /**
    * @brief HTTP响应类
    * 
    * 使用原型构造模式, 因此对于响应行部分, 一旦生成则不允许修改. 只能重新clone.
    * 
    * 对于参数和消息体则允许重新设置.
    */
   class HttpResponse : public lzx::dlagon::interface::Response{

   public:
      HttpResponse(){}
      HttpResponse(int code, HttpArgument *argument, std::string body) {
         if (code == 200){
            head_ = HttpHeadFactory::GetInstant()->GetHttpResponseHead("200 OK HTTP/1.1");
         }else if (code == 404){
            head_ = HttpHeadFactory::GetInstant()->GetHttpResponseHead("404 NOT_FOUND HTTP/1.1");
         }
         argument_ = argument;
         body_ = new HttpResponseBody(body);
      }
      const std::string ToString() const override;
      void SetBody(const std::string &str){
         
         body_ = new HttpResponseBody(str);
      }
      HttpResponse Clone();
   
      static HttpResponse HTTP_HTML_200;
      static HttpResponse HTTP_HTML_404;
   private:
      // HttpArgument *argument_;
      std::set<Cookie> cookies_;
   };
}


#endif //LZX_DLAGON_HTTP_RESPONSE_H_