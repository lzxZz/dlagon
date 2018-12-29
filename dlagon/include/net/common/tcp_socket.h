#ifndef DLAGON_NET_COMMON_TCP_SOCKET_H_
#define DLAGON_NET_COMMON_TCP_SOCKET_H_

#include "net/common/socket.h"

namespace dlagon{

namespace net{

   class TcpSocket : public Socket{
   public:
      TcpSocket(int fd)
         : Socket(fd) {}
      TcpSocket()
         : Socket(Socket::New()) {}

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
   

   };

} //namespace net
} //namespace dlagon

#endif //DLAGON_NET_COMMON_TCP_SOCKET_H_