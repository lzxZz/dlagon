// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.1

/*
    本文件声明HTTP响应头的协议部分,即HTTP响应的第一行
    并声明了常用的静态对象.
*/


#ifndef DLAGON_HTTP_RESPONSE_PROTOCOL_H_
#define DLAGON_HTTP_RESPONSE_PROTOCOL_H_

#include <string>
namespace dlagon
{
    namespace http
    {   
        /**
         *
         *  HTTP响应协议头 
         * 
         **/
        class HttpResponseProtocol
        {
        public:
            HttpResponseProtocol(std::string version, int code, std::string info)
                : version_(version), state_code_(code), state_info_(info) {}

            HttpResponseProtocol()
                : HttpResponseProtocol("HTTP/1.1", 200, "OK") {}
            const std::string ToString() const;
        private:
            const std::string                                   version_;
            const int                                           state_code_;
            const std::string                                   state_info_;
        };

        /**
         *  RFC2612文档中列举出来的所有的情况都定义为静态常量成员.
        **/
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_200{"HTTP/1.1", 200, "OK"};
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_201;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_202;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_203;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_204;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_205;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_206;
        
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_300;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_301;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_302;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_303;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_304;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_305;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_306;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_307;
        
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_400;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_401;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_402;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_403;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_404;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_405;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_406;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_407;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_408;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_409;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_410;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_411;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_412;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_413;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_414;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_415;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_416;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_417;

        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_500;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_501;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_502;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_503;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_504;
        static const HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_505;
    } //namespace http
} //namespace dlagon

#endif //DLAGON_HTTP_RESPONSE_PROTOCOL_H_