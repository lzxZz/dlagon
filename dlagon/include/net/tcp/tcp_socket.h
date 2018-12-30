#ifndef DLAGON_NET_COMMON_TCP_SOCKET_H_
#define DLAGON_NET_COMMON_TCP_SOCKET_H_

#include "net/common/socket.h"

namespace dlagon{

namespace net{

namespace tcp{

class TcpSocket : public Socket{
public:
    TcpSocket(int fd)
        : Socket(fd) {}
    TcpSocket()
        : Socket(Socket::New()) {}
    TcpSocket(const Socket &sock)
        : Socket(sock.PointerFD()) {}
    TcpSocket(const TcpSocket &sock)
        : Socket(sock.PointerFD()) {}
    auto Send(const std::string &str)   
        -> void;
    auto Send(const char *str, size_t len)   
        -> void;
    auto Receive() 
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
        -> std::tuple<TcpSocket, EndPoint>;
   

};

} //namespace tcp

} //namespace net

} //namespace dlagon

#endif //DLAGON_NET_COMMON_TCP_SOCKET_H_