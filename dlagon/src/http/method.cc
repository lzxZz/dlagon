// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.24

/*
   对`http/method.h`的实现
*/

#include "http/method.h"
#include <string>

using std::string;
namespace dlagon{
   namespace http{
      
      HttpMethod StringToMethod(string method){
         for (auto &c : method)
         {
            c = toupper(c);
         }
         if (method == "GET")
         {
            return HttpMethod::GET;
         } else if (method == "POST")
         {
            return HttpMethod::POST;
         }else if (method == "HEAD")
         {
            return HttpMethod::HEAD;
         } else if (method == "PUT")
         {
            return HttpMethod::PUT;
         } else if (method == "DELETE")
         {
            return HttpMethod::DELETE;
         } else if (method == "TRACE")
         {
            return HttpMethod::TRACE;
         } else if (method == "CONNENCTION")
         {
            return HttpMethod::CONNENCTION;
         }
         return HttpMethod::UNKNOWN;
      }

      const string MethodToString(const HttpMethod &method){
         switch (method){
            case HttpMethod::GET:
               return "GET";
            case HttpMethod::POST:
               return "POST";
            case HttpMethod::HEAD:
               return "GEHEADT";
            case HttpMethod::PUT:
               return "PUT";
            case HttpMethod::DELETE:
               return "DELETE";
            case HttpMethod::TRACE:
               return "TRACE";
            case HttpMethod::CONNENCTION:
               return "CONNENCTION";
            default:
               return "UNKNOWN";
         }
      }

   } //namespace http


} //namespace dlagon