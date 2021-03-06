// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.25

/*
   对`net/common/end_point.h`的实现
*/

#include "net/common/end_point.h"

#include <string>

#include "common/debug.h"
using std::string;

namespace dlagon{

namespace net{

   const string AF_INET_NAME = "IPv4";
   const string AF_INET6_NAME = "IPv6";
   const string AF_LOCAL_NAME = "Unix域协议";
   const string AF_ROUTE_NAME = "路由套接字";
   const string AF_KEY_NAME = "密钥套接字";
   const string AF_UNKNOWN_NAME = "未知类型";
   
   const string &EndPoint::FamilyToString(const int falmily) const{  
        DLAGON_CALL_DEBUG;
      switch (falmily)
      {
         case (AF_INET):
            return AF_INET_NAME;
         case (AF_INET6):
            return AF_INET6_NAME;
         case (AF_LOCAL):
            return AF_LOCAL_NAME;
         case (AF_ROUTE):
            return AF_ROUTE_NAME;
         case (AF_KEY):
            return AF_KEY_NAME;
      }
      return AF_UNKNOWN_NAME;
   }

   const std::string EndPoint::Debug() const{
        DLAGON_CALL_DEBUG;
         using std::ostringstream;
         
         ostringstream os;
         os << "----------------------------" << "\n";

         char str[INET_ADDRSTRLEN];
         //将整形的地址转换为文本型的点分十进制
         string addr = inet_ntop(AF_INET, 
                           &(sock_addr_.sin_addr.s_addr), 
                           str, sizeof(str));
         os << "地址 :" <<  addr << "\n";
         os << "族 :" << FamilyToString(sock_addr_.sin_family) << "\n";
         //将端口从网络字节序转换为主机字节序
         os << "端口号 :" << ntohs(sock_addr_.sin_port) << "\n";
         os << "----------------------------" << "\n";
         return os.str();
      }  

      const struct sockaddr *EndPoint::ScoketAddress() const {
        DLAGON_CALL_DEBUG;
         return (struct sockaddr*)&sock_addr_;
      }
      const int EndPoint::Port() const{
        DLAGON_CALL_DEBUG;
         return sock_addr_.sin_port;
      }
      const int EndPoint::Size() const{
        DLAGON_CALL_DEBUG;
         return sizeof(sock_addr_);
      }
      void EndPoint::Port(const int port){
        DLAGON_CALL_DEBUG;
         // 注意使用htons进行转换
         sock_addr_.sin_port = htons(port);
      }
      void EndPoint::IP(const std::string &ip){
        DLAGON_CALL_DEBUG;
         inet_pton(AF_INET, ip.c_str(), &sock_addr_.sin_addr);
      }

} //namespace net

} //namespace dlagon
