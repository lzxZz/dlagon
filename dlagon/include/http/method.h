// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.28

/*
    本文件声明HTTP方法枚举,和相关的处理函数
*/


#ifndef DLAGON_HTTP_METHOD_H_
#define DLAGON_HTTP_METHOD_H_
#include <string>
namespace dlagon
{
    namespace http
    {   
        /*
         *  HTTP方法枚举类 
        **/
        enum class HttpMethod
        {   
            GET,
            POST,
            HEAD,
            PUT,
            DELETE,
            TRACE,
            CONNENCTION,
            UNKNOWN
        };

        auto StringToMethod(std::string method)
            -> HttpMethod ;
        auto MethodToString(HttpMethod method)
            -> const std::string ;

    } //namespace http
} //namespace dlagon

#endif //DLAGON_HTTP_METHOD_H_