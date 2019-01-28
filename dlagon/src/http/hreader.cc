// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.11

/*
   对`http/header.h`的实现
*/

#include <iostream>
#include "common/debug.h"

#include "http/header.h"

#include <string>

using std::string;
// using std::unordered_map;

namespace dlagon {

namespace http {
    const HttpMethod HttpRequestHeader::Method() const{
        DLAGON_CALL_DEBUG;
        return method_;
    }
    const Path &HttpRequestHeader::Path() const{
        DLAGON_CALL_DEBUG;
        return path_;
    }
    const string HttpRequestHeader::Version() const{
        DLAGON_CALL_DEBUG;
        return version_;
    }

    const ArgumentTable &HttpRequestHeader::ArgTable(){
        DLAGON_CALL_DEBUG;
        return arg_table_;
    }

    void HttpRequestHeader::AddArg(const string &key, const string &value){
        DLAGON_CALL_DEBUG;
        arg_table_.Set(key, value);
    }

    void HttpRequestHeader::RemoveArg(const string &key){
        DLAGON_CALL_DEBUG;
        arg_table_.Remove(key);
    }

    const string HttpRequestHeader::GetArg(const string &key){
        DLAGON_CALL_DEBUG;
        return arg_table_.Get(key);
    }

    ArgumentTable HttpRequestHeader::Cookies(){
        DLAGON_CALL_DEBUG;
        return cookies_;
    }
    void HttpRequestHeader::AddCookie(const Cookie &cookie){
        DLAGON_CALL_DEBUG;
        cookies_.Set(cookie.Name(), cookie.Value());
    }

    void HttpRequestHeader::AddCookie(const string &key, const string &value){
        DLAGON_CALL_DEBUG;
        cookies_.Set(key, value);
    }
    void HttpRequestHeader::ClearCookie(){
        DLAGON_CALL_DEBUG;
        cookies_.Clear();
    }

    const string HttpRequestHeader::Debug() const
    {
        DLAGON_CALL_DEBUG;
        // TODO 等待添加具体数据内容
        return "";
    }

     bool operator==(const HttpRequestHeader &lhs,const  HttpRequestHeader &rhs)
    {
        DLAGON_CALL_DEBUG;
        return (lhs.Method() == rhs.Method()
                && lhs.Path() == rhs.Path()
                && lhs.Version() == rhs.Version());
    }
    bool operator!=(const HttpRequestHeader &lhs,const  HttpRequestHeader &rhs)
    {
        DLAGON_CALL_DEBUG;
        return !(lhs == rhs);
    }
    
    bool operator==( HttpRequestHeader &lhs,  HttpRequestHeader &rhs)
    {
        DLAGON_CALL_DEBUG;
        return (lhs.Method() == rhs.Method()
                && lhs.Path() == rhs.Path()
                && lhs.Version() == rhs.Version());
    }
    bool operator!=( HttpRequestHeader &lhs,  HttpRequestHeader &rhs)
    {
        DLAGON_CALL_DEBUG;
        return !(lhs == rhs);
    }

    void HttpResponseHeader::AddCookie(const Cookie &cookie){
        DLAGON_CALL_DEBUG;
        cookies_.push_back(cookie);
    }
    void HttpResponseHeader::ClearCookie(){
        DLAGON_CALL_DEBUG;
        cookies_.clear();
    }

    const string HttpResponseHeader::ToString() const{
        DLAGON_CALL_DEBUG;
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
        DLAGON_CALL_DEBUG;
        return arg_table_;
    }


}   //namespace http


}  // namespace dlagon