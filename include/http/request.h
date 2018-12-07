#ifndef DLAGON_HTTP_REQUEST_H_
#define DLAGON_HTTP_REQUEST_H_

#include <string>
#include <unordered_map>

#include "http/defs.h"
#include "http/arg.h"

namespace dlagon
{
    class Http_Request{
    public:
        std::unordered_map<std::string, std::string>        header;         //请求头的键值对
        std::string                                         body;           //请求数据体
        Http_method                                         method;         //请求的方法
        std::string                                         method_str;     //请求方法的字符串表示
        std::string                                         path;           //请求的路径
        std::string                                         version;        //请求的协议版本
        Argument                                            arg;            //get请求的参数
    };
    Http_Request parse_to_request(const std::string &str);
}

#endif // DLAGON_HTTP_REQUEST_H_