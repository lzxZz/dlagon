// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.25

/*
   对`net/common/socket.h`的实现
*/


#include "net/common/socket.h"

#include <arpa/inet.h>
#include <errno.h>

#include <netinet/in.h>
#include <sys/socket.h>


#include <sstream>
using std::string;




namespace dlagon{
namespace net{
namespace {
   // UNP中的writern函数
   ssize_t writern(int fd, const void *vptr, size_t n)
   {
      size_t nleft = n;
      ssize_t nwritten;
      const char *ptr;
      
      ptr = static_cast<const char*>(vptr);
      
      while (nleft > 0){
         if ( (nwritten = write(fd, ptr, nleft)) <= 0){
            if (nwritten < 0 && errno == ENETRESET){
               nwritten = 0;
            }else{
               return (-1);
            }
         }
         nleft -= nwritten;
         ptr += nwritten;
      }
      return (n);
   }
   // UNP中的readn函数
   ssize_t readn(int fd, void *vptr, size_t n)
   {
      size_t nleft;
      ssize_t nread;
      char *ptr;
      ptr = static_cast<char*>(vptr);
      nleft = n;
      while (nleft > 0){
         if ( (nread = read(fd, ptr, nleft)) < 0 )  {
            if (errno == EINTR){
               nread = 0;
            }else{
               return (-1);
            }
         }else if (nread == 0){
            break;
         }
         nleft -= nread;
         ptr += nread;
      }
      return (n - nleft);
   } 
} //namesapce


   const string Socket::Receive() noexcept{   
      string content;

      char *buf = new char[BUFSIZ];
      size_t n = 0;
      do{
         n = readn(this->fd_, buf, BUFSIZ);
         char str[1024];
         sprintf(str, "%s", buf);
         puts(str);
      }while(n == BUFSIZ);
      delete[] buf;
      return content;
   }

   void Socket::Send(const string &str) noexcept{
      writern(this->fd_, str.c_str(), sizeof(str.c_str()));
   }

   void Socket::Bind(int port){
      using SA = struct sockaddr;
      // struct sockaddr_in addr;
      // bzero(&addr, sizeof(SA));
      // addr.sin_family = AF_INET;
      // addr.sin_addr.s_addr = htonl(INADDR_ANY);
      // addr.sin_port = htons(port);
      EndPoint endpoint{port};

      
      if (bind(this->fd_, endpoint.ScoketAddress(), sizeof(SA))  == -1){
         string info;
         info.append("绑定端口号失败\n");
         info.append(strerror(errno));
         info.append("\n");
         info.append(endpoint.Debug());

         throw dlagon::exception::Exception{info};
      }
   }

   void Socket::Listen(int queue_length){
      if (listen(this->fd_, queue_length) == -1){
         string info;
         info.append("监听失败\n");
         info.append("监听的文件描述符是 : ");
         info.append(std::to_string(this->fd_));
         info.append("\n");
         info.append(strerror(errno));
         info.append("\n");
         
         throw dlagon::exception::Exception{info};
      }
   }

   void Socket::Connect(EndPoint endpoint){
      using SA = struct sockaddr;

      if( connect(this->fd_, endpoint.ScoketAddress(), sizeof(SA)) == -1){
         string info;
         info.append("连接远程套接字失败\n");
         info.append(strerror(errno));
         info.append("\n");
         info.append("远程套接字信息如下\n\n");
         
         info.append(endpoint.Debug());

         throw dlagon::exception::Exception{info};
         
         
         
      }
   }

   // 阻塞版本
   Socket Socket::Accept(){
      using SA = struct sockaddr;
      struct sockaddr_in addr;
      int fd;
      socklen_t len = sizeof(addr);
      fd = accept(this->fd_, (SA *)&addr, &len);

      if (fd == -1)
      {
         string info;
         info.append("获取客户端套接字失败\n");
         info.append(strerror(errno));
         info.append("\n");
         throw exception::Exception{info};
      }
      return Socket{fd};
      
   }

   
} //namespace net

} //namespace dlagon