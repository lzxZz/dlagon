// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.24

/*
    本文件声明基本套接字,对普通的套接字函数进行了封装,   
*/

#ifndef DLAGON_COMMON_SOCKET_H_
#define DLAGON_COMMON_SOCKET_H_
#include <unistd.h>
#include <string>

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
        Socket(int fd) : fd_(fd) {}

        const int FD() const{
            return fd_;
        }
        void Send(const std::string &str);
        const std::string &&Receive();
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