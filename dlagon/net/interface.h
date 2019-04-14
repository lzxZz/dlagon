/**
 * @file server.h
 * @author lzxZz (616281384@qq.com)
 * @description client和server的接口
 * @version 0.1
 * @date 2019-04-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <memory>

namespace lzx::dlagon::net{

inline 
namespace core{
    /**
    * @description 
    * 
    */
    class IServer{
    public:
        virtual void Bind() = 0;
        virtual void Listen() = 0;
        virtual void Accept() = 0;
    };

    /**
     * @description 
     * 
     */
    class IClient{
    public:
        virtual void Send() = 0;
        virtual void Recevice() = 0;
        virtual void Connect() = 0;
    };



    

    

} // lzx::dlagon::net::core

}


