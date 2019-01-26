// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.30

/*
    本文件声明套接字基类, 使用共享智能指针持有套接字描述符.
    不持有具体行为
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

    // 套接字协议族
    enum class SocketFamily {
        IPv4 = AF_INET,            
        IPv6 = AF_INET6,           
        UNIX = AF_LOCAL,   //UNIX域协议       
        ROUTE = AF_ROUTE,  // 路由协议        
        KEY  = AF_KEY    //密钥协议         
    };

    // 套接字类型,前面加SOCK_即是系统定义的常量
    enum class SocketType{
        STREAM = SOCK_STREAM,     //流式套接字
        DGRAM = SOCK_DGRAM,      //数据报套接字
        SEQPACKET = SOCK_SEQPACKET,  //有序分组套接字
        RAW = SOCK_RAW        //原始套接字
    };

    // 套接字协议类型
    enum class SocketProtocolType{
        TCP = IPPROTO_TCP,     //对应于IPPROTO_TCP
        UDP = IPPROTO_UDP,     //对应于IPPROTO_UDP
        SCTP = IPPROTO_SCTP,    //对应于IPPROTO_SCTP
        IP = IPPROTO_IP
    };



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
        Socket(const std::shared_ptr<const int> &pointer_fd) 
            : fd_(pointer_fd) {}
        Socket(const Socket &sock)
            : fd_(sock.PointerFD()) {}

        static Socket New(SocketFamily family = SocketFamily::IPv4, 
                        SocketType type = SocketType::STREAM, 
                        SocketProtocolType protocol = SocketProtocolType::IP);
        const std::shared_ptr<const int> PointerFD() const;
        const int FD() const;
        
    private:
        std::shared_ptr<const int> fd_;
    };

    } //namespace net
} //namespace dlagon

#endif //DLAGON_COMMON_SOCKET_H_