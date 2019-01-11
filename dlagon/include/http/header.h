// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.11

/*
    本文件声明的HttpRequestHeader类,用于表示HTTP请求头
    本文件声明的HttpResponseHeader类,用于表示HTTP响应头
    HTTP请求头作为HTTP请求(http/request.h)的组成部分.
    HTTP响应头作为HTTP响应(http/response.h)的组成部分.

    在HttpResponseHeader中新增了Cookie集合.
*/

#ifndef DLAGON_HTTP_HEADER_H_
#define DLAGON_HTTP_HEADER_H_

#include <string>
#include <unordered_map>
#include <vector>

#include "common/path.h"
#include "http/cookie.h"
#include "http/method.h"
#include "http/response_protocol.h"

namespace dlagon
{
    namespace http
    {
        
        
        /*
        * HTTP请求头
        * 包含请求方法,路径,协议
        * 请求参数表
        */
        class HttpRequestHeader{
        public:
            auto Method() const
                -> const HttpMethod 
            {
                return method_;
            }
            auto Path() const
                -> const dlagon::Path&
            {
                return path_;
            }
            //因为这个字符串不会很长,因此返回副本,而不是引用
            auto Version() const
                -> const std::string 
            {
                return version_;
            }
            auto ArgTable()
                ->const std::unordered_map<std::string, std::string> &
            {
                return arg_table_;
            }

            auto Debug()
                -> const std::string;

            HttpRequestHeader(dlagon::http::HttpMethod  method, 
                                std::string path, 
                                std::string version)
                : method_(method), path_(path), version_(version) {}

            HttpRequestHeader(dlagon::http::HttpMethod  method, 
                                dlagon::Path path, 
                                std::string version)
                : method_(method), path_(path), version_(version) {}
            
            //下面两组构造函数是带有参数列表的
            HttpRequestHeader(dlagon::http::HttpMethod  method, 
                                std::string path, 
                                std::string version,
                                std::unordered_map<std::string, std::string>     args)
                : method_(method), path_(path), version_(version), arg_table_(args) {}

            HttpRequestHeader(dlagon::http::HttpMethod  method, 
                                dlagon::Path path, 
                                std::string version,
                                std::unordered_map<std::string, std::string>     args)
                : method_(method), path_(path), version_(version), arg_table_(args) {}
            
            std::vector<Cookie> Cookies(){
                return cookies_;
            }

            void AddCookie(Cookie cookie){
                cookies_.push_back(cookie);
            }
            void ClearCookie(){
                cookies_.clear();
            }
            
        private:
            /*
            *   所有成员都是常量
            *   参数表是引用,因此能够修改
            */
            const HttpMethod                                    method_;
            const dlagon::Path                                  path_;
            const std::string                                   version_;
            const std::unordered_map<std::string, std::string>  arg_table_;
            std::vector<Cookie>                                 cookies_;       //暂未实现
            
        };
        
        //请求头的比较没有比较请求头参数列表
        bool operator==(const HttpRequestHeader &lhs, const HttpRequestHeader &rhs);
        bool operator!=(const HttpRequestHeader &lhs, const HttpRequestHeader &rhs);

        bool operator==(HttpRequestHeader &lhs, HttpRequestHeader &rhs);
        bool operator!=(HttpRequestHeader &lhs, HttpRequestHeader &rhs);

        /*
         * HTTP响应头
         * 包含响应协议,
         * 响应参数表
         */
        class HttpResponseHeader{
        public:
            HttpResponseHeader(const HttpResponseProtocol protocol)
                : protocol_(protocol) {}
            const std::string ToString() const;
            // 不能返回常量对象,返回常量对象将会导致无法调用emplace方法.
            auto ArgTable()
                -> std::unordered_map<std::string, std::string> &;
            void AddCookie(Cookie cookie){
                cookies_.push_back(cookie);            
            }
            void ClearCookie(){
                cookies_.clear();
            }
        private:
            /*
            *   所有成员都是常量
            */
            const HttpResponseProtocol                          protocol_;
            std::unordered_map<std::string, std::string>        arg_table_;
            std::vector<Cookie>                                 cookies_;
        };
        bool operator==(const HttpResponseHeader &lhs, const HttpResponseHeader &rhs);
        bool operator!=(const HttpResponseHeader &lhs, const HttpResponseHeader &rhs);
        bool operator==(HttpResponseHeader &lhs, HttpResponseHeader &rhs);
        bool operator!=(HttpResponseHeader &lhs, HttpResponseHeader &rhs);
    } //namespace http

} // namespace dlagon

#endif //DLAGON_HTTP_HEADER_H_