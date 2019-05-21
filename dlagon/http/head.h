/**
 * @file head.h
 * @author lzxZz (616281384@qq.com)
 * @brief HTTP请求头和响应头声明
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_HTTP_HEAD_H_
#define LZX_DLAGON_HTTP_HEAD_H_

#include "dlagon/interface/protocol/head.h"
#include "dlagon/http/protocol.h"
#include <string>

namespace lzx::dlagon::http{
   // class HttpRequestHeadTest;
   class HttpRequestHead : public lzx::dlagon::interface::ProtocolHead{
      friend class HttpRequestHeadTest;
      friend class HttpHeadFactory;
      friend bool operator==(const HttpRequestHead &lhs, const HttpRequestHead &rhs);
      friend bool operator!=(const HttpRequestHead &lhs, const HttpRequestHead &rhs);
      // friend void HttpRequestHeadTest::SetUp();
      HttpRequestHead *FromString(const std::string &str) ;
   public:
      std::string ToString() override;
   private:
      HttpMethod method_;
      std::string url_;
      HttpProtocolVerstion protocol_;
   public:
      HttpRequestHead(  const std::string &method,
                        const std::string &url,
                        const std::string &protocol)
         :  method_(HttpMethodFromString(method)), 
            url_(url), 
            protocol_(HttpProtocolVerstionFromString(protocol))
         {}
   };

   class HttpResponseHead : public lzx::dlagon::interface::ProtocolHead{
      
      HttpResponseHead *FromString(const std::string &str) ;
   public:
      std::string ToString() override;
   private:
      
   };

   class HttpHeadFactory{
   public:
      static HttpHeadFactory *GetInstant();
      HttpRequestHead *GetHttpRequestHead(const std::string &str);
      HttpResponseHead *GetHttpResponseHead(const std::string &str);
   private:
      static HttpHeadFactory *factory_ ;
   };
}


#endif //LZX_DLAGON_HTTP_HEAD_H_