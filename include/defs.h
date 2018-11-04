#ifndef __DEFS_H
#define __DEFS_H


#include <unordered_map>
#include <string>

namespace dlagon{
    enum class Http_method{
        GET,
        POST,
        HEAD,
        PUT,
        DELETE,
        TRACE,
        CONNENCTION,
        OTHER
        
    };
    enum class Mime_type{

    };

    
    class Http_request{
    public:
        std::unordered_map<std::string, std::string>        header;         //请求头的键值对
        std::string                                         body;           //请求数据体
        Http_method                                         method;         //请求的方法
        std::string                                         method_str;     //请求方法的字符串表示
        std::string                                         path;           //请求的路径
        std::string                                         version;        //请求的协议版本
    };

    // class Http_response{
    //     int                                                 state;          //状态码
    //     std::string                                         state_info;     //状态码对应的字段
    //     std::string                                         version;        //协议版本

    // };
    Http_request parse_to_request(const std::string&);

    ///http方法枚举类型
    
    
}

#endif