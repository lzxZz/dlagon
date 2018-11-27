#ifndef DLAGON_HTTP_RESPONSE_H_
#define DLAGON_HTTP_RESPONSE_H_


#include <string>
#include <unordered_map>
#include <fstream>

namespace dlagon
{
    class Http_Response
    {
    public:
        explicit Http_Response(std::string v, int code, std::string s) : version(v), state(code), state_info(s)
        {
            
        }
        void set_body(std::string file);
        void set_body_by_content(std::string content)
        {
            body = content;
        }
    // private:
        std::string                                         version;        //协议版本
        int                                                 state;          //状态码
        std::string                                         state_info;     //状态码对应的字段
        std::unordered_map<std::string, std::string>        header;         //响应头
        std::string                                         body;           //响应体
        
    };

}


#endif //DLAGON_HTTP_RESPONSE_H_