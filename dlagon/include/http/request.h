// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.24

/*
    本文件声明HTTP请求类, 由HTTP请求头和请求体两部分组成.
    并且声明了静态函数,用于构造对象.
*/

#ifndef DLAGON_HTTPP_REQUEST_H_
#define DLAGON_HTTPP_REQUEST_H_

#include <string>

#include "http/header.h"

namespace dlagon
{
namespace http
{
    /*
     *  HTTP请求类,
     * 推荐使用静态方法Parse()进行构造
     * 
     * example: HttpReques  req = HttpRequest::Parse("请求字符串");
     * 
    **/

    class HttpRequest{
    public:
        HttpRequest(HttpRequestHeader header, std::string body)
            : header_(header) ,body_(body) {}
        // HttpRequest(HttpRequestHeader                           header, 
        //             std::unordered_map<std::string, std::string>     args,
        //             std::string                                body)
        //     : header_(header) ,body_(body) {}
        
        const std::string Debug();

        //获取请求体
        std::string             Body()      const{
            return body_;
        }          
        //获取请求头
        HttpRequestHeader       Header()    const{
            return header_;
        }          
        //静态函数,用于将字符串转换为HTTP请求
        static HttpRequest      Parse(const std::string &str);
    private:
        const HttpRequestHeader header_;
        const std::string       body_;       //请求体
    };

    bool operator==(const HttpRequest &lhs, const HttpRequest &rhs);
    bool operator!=(const HttpRequest &lhs, const HttpRequest &rhs);
    
}//namespace http

} //namespace dlagon

#endif //DLAGON_HTTPP_REQUEST_H_