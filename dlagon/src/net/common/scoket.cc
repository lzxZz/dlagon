// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.30

/*
   对`net/common/socket.h`的实现
*/


#include "net/common/socket.h"

#include <arpa/inet.h>
#include <errno.h>

#include <netinet/in.h>
#include <sys/socket.h>

#include "common/debug.h"

#include <memory>
#include <sstream>
using std::string;
using std::shared_ptr;

#include <iostream>


namespace dlagon{
namespace net{
// namespace {
//    // UNP中的writern函数
//    ssize_t writern(int fd, const void *vptr, size_t n)
//    {
//       size_t nleft = n;
//       ssize_t nwritten;
//       const char *ptr;
      
      

//       ptr = static_cast<const char*>(vptr);

//       string s = ptr;
//       std::cout << "writern : 数据 : " << s  << "\n";
//       std::cout << "writern : 长度 : " << n  << "\n";
      
//       while (nleft > 0){
//          if ( (nwritten = write(fd, ptr, nleft)) <= 0){
//             if (nwritten < 0 && errno == ENETRESET){
//                nwritten = 0;
//             }else{
//                return (-1);
//             }
//          }
//          nleft -= nwritten;
//          ptr += nwritten;
//       }
//       return n;
//    }
//    // ----------
//    // ----------
//    // DEPRECATED
//    // ----------
//    // ----------
//    // UNP中的readn函数
//    ssize_t readn(int fd, void *vptr, size_t n)
//    {
//       size_t nleft;
//       ssize_t nread;
//       char *ptr;

//       ptr = static_cast<char*>(vptr);
//       nleft = n;
//       while (nleft > 0){
//          //使用http例子时第二次调用readn函数崩溃
//          // 目前弃用
//          if ( (nread = read(fd, ptr, nleft)) < 0 )  {  
//             if (errno == EINTR){
//                nread = 0;
//             }else{
//                return (-1);
//             }
//          }else if (nread == 0){
//             break;
//          }
//          nleft -= nread;
//          ptr += nread;
//       }
//       return (n - nleft);
//    } 
// } //namesapce

   
   void Socket::release_socket(const int* const fd){
        DLAGON_CALL_DEBUG;
      // std::cout << "---------xigou----------\n";    
      if (close(*fd) == -1){
         string info = "Close 套接字描述符失败\n要关闭的描述符为 : ";
         info.append(std::to_string(*fd));
         info.append("\n错误消息为 : ");
         info.append(strerror(errno));
         throw exception::Exception{info};
      }
   }

   Socket Socket::New(SocketFamily family, 
                        SocketType type, 
                        SocketProtocolType protocol){
        DLAGON_CALL_DEBUG;
            const int fd = socket(static_cast<int>(family),
                                static_cast<int>(type), 
                                static_cast<int>(protocol));
            if (fd == -1)
            {
                throw dlagon::exception::Exception("获取套接字描述符失败");
            }
            return Socket{fd};
        }
        const std::shared_ptr<const int> Socket::PointerFD() const{
            return fd_;
        }
        const int Socket::FD() const{
            return *fd_;
        }
        

   
} //namespace net

} //namespace dlagon