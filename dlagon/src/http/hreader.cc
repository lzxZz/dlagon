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

    const string HttpRequestHeader::Debug()
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