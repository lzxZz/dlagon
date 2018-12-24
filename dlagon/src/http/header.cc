// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.24

/*
   对`http/header.h`的实现
*/


#include "http/header.h"

#include <string>

using std::string;

namespace dlagon {

namespace http {

    const string HttpRequestHeader::Debug()
    {
        // TODO 等待添加具体数据内容
        return "";
    }


    bool operator==(const HttpRequestHeader &lhs, const HttpRequestHeader &rhs)
    {
        return (lhs.Method() == rhs.Method()
                && lhs.Path() == rhs.Path()
                && lhs.Version() == rhs.Version());
    }
    bool operator!=(const HttpRequestHeader &lhs, const HttpRequestHeader &rhs)
    {
        return !(lhs == rhs);
    }

}   //namespace http


}  // namespace dlagon