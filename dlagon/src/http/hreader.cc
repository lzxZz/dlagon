// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.11

/*
   对`http/header.h`的实现
*/

#include <iostream>

#include "http/header.h"

#include <string>

using std::string;
// using std::unordered_map;

namespace dlagon {

namespace http {
    const HttpMethod HttpRequestHeader::Method() const{
        return method_;
    }
    const Path &HttpRequestHeader::Path() const{
        return path_;
    }
    const string HttpRequestHeader::Version() const{
        return version_;
    }

    const ArgumentTable &HttpRequestHeader::ArgTable(){
        return arg_table_;
    }

    void HttpRequestHeader::AddArg(const string &key, const string &value){
        arg_table_.Set(key, value);
    }

    void HttpRequestHeader::RemoveArg(const string &key){
        arg_table_.Remove(key);
    }

    const string HttpRequestHeader::GetArg(const string &key){
        return arg_table_.Get(key);
    }

    ArgumentTable HttpRequestHeader::Cookies(){
        return cookies_;
    }
    void HttpRequestHeader::AddCookie(const Cookie &cookie){
        cookies_.Set(cookie.Name(), cookie.Value());
    }

    void HttpRequestHeader::AddCookie(const string &key, const string &value){
        cookies_.Set(key, value);
    }
    void HttpRequestHeader::ClearCookie(){
        cookies_.Clear();
    }

    const string HttpRequestHeader::Debug() const
    {
        // TODO 等待添加具体数据内容
        return "";
    }

     bool operator==(const HttpRequestHeader &lhs,const  HttpRequestHeader &rhs)
    {
        return (lhs.Method() == rhs.Method()
                && lhs.Path() == rhs.Path()
                && lhs.Version() == rhs.Version());
    }
    bool operator!=(const HttpRequestHeader &lhs,const  HttpRequestHeader &rhs)
    {
        return !(lhs == rhs);
    }
    
    bool operator==( HttpRequestHeader &lhs,  HttpRequestHeader &rhs)
    {
        return (lhs.Method() == rhs.Method()
                && lhs.Path() == rhs.Path()
                && lhs.Version() == rhs.Version());
    }
    bool operator!=( HttpRequestHeader &lhs,  HttpRequestHeader &rhs)
    {
        return !(lhs == rhs);
    }

    void HttpResponseHeader::AddCookie(const Cookie &cookie){
        cookies_.push_back(cookie);
    }
    void HttpResponseHeader::ClearCookie(){
        cookies_.clear();
    }

    const string HttpResponseHeader::ToString() const{
        string info;
        info.append(this->protocol_.ToString());
        // info.append("\r\n");          
        // std::cout << arg_table_.size() << "\n";          
        info.append(arg_table_.ToString());
        for (auto cookie : cookies_){
            info.append(cookie.ToString());
            info.append("\r\n");
        }
        info.append("\r\n"); // 参数表和响应体之间使用\r\n分割
        return info;
    }

    ArgumentTable &HttpResponseHeader::ArgTable(){
        return arg_table_;
    }


}   //namespace http


}  // namespace dlagon