/**
 * @file protocol.cc
 * @author lzxZz (616281384@qq.com)
 * @brief HTTP协议相关定义
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "dlagon/http/protocol.h"

using std::string;

namespace lzx::dlagon::http{

   HttpMethod HttpMethodFromString(const string  &str){
      string method = ToUpper(str);
      if ("GET" == method ){
         return HttpMethod::kGet;
      }else if ("POST" == method){
         return HttpMethod::kPost;
      }
      else{

      
         return HttpMethod::kUnknown;
      }
   }

   string HttpMethodToString(const HttpMethod method){
      switch (method){
         case HttpMethod::kGet:{
            return "GET";
         }
         case HttpMethod::kPost:{
            return "POST";
         }
         case HttpMethod::kUnknown:{
            return "UNKNOWN";
         }
      }
      return "UNKNOWN";
   }


   HttpProtocolVerstion HttpProtocolVerstionFromString(const string  &str){
      string version = ToUpper(str);
      if ("HTTP/1.1" == version){
         return HttpProtocolVerstion::kV1_1;

      }
      return HttpProtocolVerstion::kUnknown;
   }
   string HttpProtocolVerstionToString(const HttpProtocolVerstion version){
      switch (version){
         case HttpProtocolVerstion::kV1_1:{
            return "HTTP/1.1";
         }
      }
      return "UNKNOWN";
   }


}

