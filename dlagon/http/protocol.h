/**
 * @file protocol.h
 * @author lzxZz (616281384@qq.com)
 * @brief HTTPP协议相关
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_HTTP_PROTOCOL_H_
#define LZX_DLAGON_HTTP_PROTOCOL_H_

#include <string>

namespace lzx::dlagon::http{
   inline
   std::string ToUpper(const std::string &str){
      std::string result = str;
      for (auto &c : result){
         c = toupper(c);
      }
      return result;
   }

   enum class HttpProtocolVerstion{
      kV1_1,
      kUnknown,
   };
   enum class HttpMethod{
      kGet,
      kPost,
      kUnknown,
   };

   enum class HttpResponseStatus{
      kOk = 200,
      kNot_Found = 404,
   };
   
   // string HttpResponseStatusToCodeString(HttpResponseStatus status);
   std::string HttpResponseStatusToStatusString(HttpResponseStatus status);

   HttpMethod HttpMethodFromString(const std::string  &str);

   std::string HttpMethodToString(const HttpMethod method);

   HttpProtocolVerstion HttpProtocolVerstionFromString(const std::string  &str);

   std::string HttpProtocolVerstionToString(const HttpProtocolVerstion version);
}


#endif //LZX_DLAGON_HTTP_PROTOCOL_H_