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

#include <string>

#include "dlagon/http/protocol.h"
#include "dlagon/interface/protocol/head.h"

namespace lzx::dlagon::http{
   /**
    * @brief HTTP请求行
    * 
    */
   class HttpRequestHead : public lzx::dlagon::interface::ProtocolHead{
      friend class HttpRequestHeadTest;
      friend class HttpHeadFactory;
      friend bool operator==(const HttpRequestHead &lhs, const HttpRequestHead &rhs);
      friend bool operator!=(const HttpRequestHead &lhs, const HttpRequestHead &rhs);
      // friend void HttpRequestHeadTest::SetUp();
      // HttpRequestHead *FromString(const std::string &str) ;
   public:
      std::string ToString() override;
      const std::string &Uri() const{
         return url_;
      }
      const HttpMethod Type() const{
         return method_;
      }
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

   /**
    * @brief HTTP响应行
    * 
    */
   class HttpResponseHead : public lzx::dlagon::interface::ProtocolHead{
      
      // HttpResponseHead *FromString(const std::string &str) ;
   public:
      std::string ToString() override;

      HttpResponseHead(int code, std::string status, const std::string &protocol)
         :  code_(code),
            status_(status), 
            protocol_(HttpProtocolVerstionFromString(protocol))
      {}
   private:
      int code_;
      std::string status_;
      HttpProtocolVerstion protocol_;
   };

   /**
    * @brief 请求行和响应行的工厂
    * 
    */
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