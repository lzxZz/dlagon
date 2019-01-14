// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.30

/*
   本文件声明TCP套接字,对套接字进行了封装,添加了套接字的具体行为
   使用继承实现,继承自Socket
*/

#ifndef DLAGON_NET_TCP_SOCKET_H_
#define DLAGON_NET_TCP_SOCKET_H_

#include "net/common/socket.h"

namespace dlagon{

namespace net{

namespace tcp{

/***
 *      TCP套接字,继承自Socket, 添加了具体的行为,
 **/
class TcpSocket : public Socket{
public:
    TcpSocket(const int fd)
        : Socket(fd) {}
    TcpSocket()
        : Socket(Socket::New()) {}
    TcpSocket(const Socket &sock)
        : Socket(sock.PointerFD()) {}
    TcpSocket(const TcpSocket &sock)
        : Socket(sock.PointerFD()) {}

    
    auto Send(const std::string &str)   
        -> void;
    auto Send(const char* const str, const size_t len)   
        -> void;
    
    auto Receive() 
        -> const std::string;
    // 绑定到具体的端口
    auto Bind(const int port)
        -> void;        
    auto Bind(const EndPoint &endpoint)        
        -> void;        
    auto Listen(const int queue_length)
        -> void;        
    auto Listen()
        -> void {
        Listen(LISTENQ);
    }        
    auto Connect(const EndPoint &enpoint)
        -> void;   

    // 同时返回远程套接字和地址 
    // 原先使用值返回Socket的时候,
    auto Accept()
        -> std::tuple<TcpSocket, EndPoint>;
   

};

} //namespace tcp

} //namespace net

} //namespace dlagon

#endif //DLAGON_NET_COMMON_TCP_SOCKET_H_