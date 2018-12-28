// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.26

/*
    本文件声明基本套接字,对普通的套接字函数进行了封装,   
*/

#ifndef DLAGON_COMMON_SOCKET_H_
#define DLAGON_COMMON_SOCKET_H_
#include <unistd.h>

#include <tuple>
#include <string>
#include <memory>

#include "exception/exception.h"
#include "net/common/end_point.h"
// #include "net/common/client_socket.h"
#include <iostream>

namespace dlagon
{
    namespace net{

    constexpr int LISTENQ  = 1024;
    /**
     * 
     * 基本的Socket类 
     * 
     */
    class Socket{
    public:
        // 关闭对应的套接字
        static void release_socket(const int* const fd);
        
        ~Socket() {}
        // 从指定的文件描述符创建封装.
        Socket(const int fd) 
            : fd_(new int(fd), release_socket) {}
        Socket(std::shared_ptr<const int> pointer_fd) 
            : fd_(pointer_fd) {}

        static Socket New(){
            const int fd = socket(AF_INET, SOCK_STREAM, 0);
            if (fd == -1)
            {
                throw dlagon::exception::Exception("获取套接字描述符失败");
            }
            return Socket{fd};
        }
        const std::shared_ptr<const int> PointerFD() const{
            return fd_;
        }
        const int FD() const{
            return *fd_;
        }
        auto Send(const std::string &str) noexcept  //
            -> void;
        auto Send(const char *str, size_t len) noexcept  //
            -> void;
        auto Receive() noexcept
            -> const std::string;            
        auto Bind(int port)
            -> void;        
        auto Bind(EndPoint endpoint)
            -> void;        
        auto Listen(int queue_length)
            -> void;        
        auto Listen()
            -> void {
            Listen(LISTENQ);
        }        
        auto Connect(EndPoint enpoint)
            -> void;   
        // 同时返回远程套接字和地址 
        // 原先使用值返回Socket的时候,
        //    由于文件描述符在临时变量被销毁时调用了close函数
        //    必须使用指针进行返回

        auto Accept()
            -> std::tuple<Socket, EndPoint>;
        
    private:
        std::shared_ptr<const int> fd_;
    };

    } //namespace net
} //namespace dlagon

#endif //DLAGON_COMMON_SOCKET_H_