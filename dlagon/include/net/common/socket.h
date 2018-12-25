// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.25

/*
    本文件声明基本套接字,对普通的套接字函数进行了封装,   
*/

#ifndef DLAGON_COMMON_SOCKET_H_
#define DLAGON_COMMON_SOCKET_H_
#include <unistd.h>
#include <string>

#include "exception/exception.h"
#include "net/common/end_point.h"
namespace dlagon
{
    namespace net{

    
    /**
     * 
     * 基本的Socket类 
     * 
     */
    class Socket{
    public:
        virtual ~Socket()
        {
            close(fd_);
        }
        // 从指定的文件描述符创建封装.
        Socket(int fd) : fd_(fd) {}
        
        static Socket New(){
            int fd = socket(AF_INET, SOCK_STREAM, 0);
            if (fd == -1)
            {
                throw dlagon::exception::Exception("获取套接字描述符失败");
            }
            return Socket(fd);
        }

        const int FD() const{
            return fd_;
        }
        void Send(const std::string &str) noexcept;
        const std::string Receive() noexcept;
        void Bind(int port);
        void Listen(int queue_length);
        void Connect(EndPoint enpoint);
        Socket Accept();

    private:
        const int fd_;
    };

    } //namespace net
} //namespace dlagon

#endif //DLAGON_COMMON_SOCKET_H_