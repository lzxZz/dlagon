/**
 * @file head.cc
 * @author lzxZz (616281384@qq.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "dlagon/http/head.h"

#include <sstream>

using std::istringstream;
using std::string;


namespace lzx::dlagon::http{
   HttpHeadFactory *HttpHeadFactory::factory_ = nullptr;
   

   HttpHeadFactory *HttpHeadFactory::GetInstant(){
      if (factory_ == nullptr){
         factory_ = new HttpHeadFactory();
      }
      return factory_;
   }

   HttpRequestHead *HttpHeadFactory::GetHttpRequestHead(const std::string &str){
      istringstream is(str);
      string method, url, protocol;
      is >> method >> url >> protocol;
      return new HttpRequestHead{method, url, protocol};
   }

   HttpResponseHead *HttpHeadFactory::GetHttpResponseHead(const std::string &str){
      istringstream is(str);
      int code;
      string status, protocol;
      is >> code >> status >> protocol;
      return new HttpResponseHead{code, status, protocol};
   }
   string HttpResponseHead::ToString(){
      return std::to_string(code_) + " "  + status_ + " " + HttpProtocolVerstionToString(protocol_) + "\r\n";
   }

   string HttpRequestHead::ToString(){
      return HttpMethodToString(method_) + " "  + url_ + " " + HttpProtocolVerstionToString(protocol_) + "\r\n";
   }

   bool operator==(const HttpRequestHead &lhs, const HttpRequestHead &rhs){
      return  (lhs.method_ == rhs.method_ &&
               lhs.url_ == rhs.url_ &&
               lhs.protocol_ == rhs.protocol_);
   }

   bool operator!=(const HttpRequestHead &lhs, const HttpRequestHead &rhs){
      return !(lhs == rhs);
   }


}