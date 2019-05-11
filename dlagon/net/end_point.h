// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.26

/*
   本文件声明EndPoint,对普通的struct sockaddr_in进行了封装,
   使用组合实现,而非继承

   TODO 将这个类实现为通用套接字对象,并定义若干其他套接字转换过来的方法
*/

#ifndef LZX_DLAGON_NET_COMMON_ENDPOINT_H_
#define LZX_DLAGON_NET_COMMON_ENDPOINT_H_

#include <netinet/in.h>
#include <sys/socket.h>

#include <cstring>
#include <sstream>
#include <string>
#include <arpa/inet.h>

namespace lzx::dlagon::net{

   /**
    *    
    *    EndPoint类,表示一个连接对象,是struct sockaddr_in的封装
    * 
   **/
   class EndPoint{
   public:

      // 返回地址时转换为通用socket地址结构,
      const struct sockaddr *ScoketAddress() const;
      const int Port() const;
      const int Size() const;
      void Port(const int port);
      void IP(const std::string &ip);

      EndPoint(const int port){
         bzero(&sock_addr_, sizeof(struct sockaddr_in));
         sock_addr_.sin_family = AF_INET;
         sock_addr_.sin_addr.s_addr = htonl(INADDR_ANY);
         sock_addr_.sin_port = htons(port);
      }
      EndPoint(const sockaddr_in &addr){
         bzero(&sock_addr_, sizeof(struct sockaddr_in));
         sock_addr_.sin_family = addr.sin_family;
         sock_addr_.sin_addr.s_addr = addr.sin_addr.s_addr;
         sock_addr_.sin_port = addr.sin_port;
      }

      //显示EndPoint数据成员为可读格式.
      const std::string Debug() const;
      
   private:
      //将协议从AF_XX转换为可读的文本
      const std::string &FamilyToString(int family) const;
      struct sockaddr_in sock_addr_;
   };

} //namespace net

#endif //DLAGON_NET_COMMON_ENDPOINT_H_