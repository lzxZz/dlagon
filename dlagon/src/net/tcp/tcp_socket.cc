// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.30

/*
   对net/tcp/tcp_socket.h的实现
*/


#include "net/tcp/tcp_socket.h"


using std::string;

namespace dlagon{

namespace net{

namespace tcp{



   void TcpSocket::Send(const string &str) {
      write(this->FD(), str.c_str(), str.size());
   }

   void TcpSocket::Send(const char *str, size_t len){
      write(this->FD(), str, len);
   }

   const string TcpSocket::Receive(){
      string content;

      char *buf = new char[BUFSIZ];
      size_t n = 0;
      do{
         n = read(this->FD(), buf, BUFSIZ);      // 2018.12.26修改为read函数
         
         content.append(buf, n);
      }while(n == BUFSIZ);
      delete[] buf;
      return content;
   }

   void TcpSocket::Bind(int port){
      Bind(EndPoint(port));
   }
   void TcpSocket::Bind(EndPoint endpoint){
      if(bind(this->FD(), endpoint.ScoketAddress(), endpoint.Size())  == -1){
         string info;
         info.append("绑定端口号失败\n");
         info.append(strerror(errno));
         info.append("\n");
         info.append(endpoint.Debug());

         throw dlagon::exception::Exception{info};
      }
   }

   

   void TcpSocket::Listen(int queue_length){
      if (listen(this->FD(), queue_length) == -1){
         string info;
         info.append("监听失败\n");
         info.append("监听的文件描述符是 : ");
         info.append(std::to_string(this->FD()));
         info.append("\n");
         info.append(strerror(errno));
         info.append("\n");
         
         throw dlagon::exception::Exception{info};
      }
   }

   void TcpSocket::Connect(EndPoint endpoint){
      if( connect(this->FD(), endpoint.ScoketAddress(), endpoint.Size()) == -1){
         string info;
         info.append("连接远程套接字失败\n");
         info.append(strerror(errno));
         info.append("\n");
         info.append("远程套接字信息如下\n\n");
         
         info.append(endpoint.Debug());

         throw dlagon::exception::Exception{info};
         
         
         
      }
   }

   std::tuple<TcpSocket, EndPoint> TcpSocket::Accept(){
      using SA = struct sockaddr;
      struct sockaddr_in addr;
      int fd;
      socklen_t len = sizeof(addr);
      fd = accept(this->FD(), (SA *)&addr, &len);
      
      if (fd == -1)
      {
         string info;
         info.append("获取客户端套接字失败\n");
         info.append(strerror(errno));
         info.append("\n");
         throw exception::Exception{info};
      }
      return  std::make_tuple(TcpSocket{fd} ,EndPoint{addr});
   }

} //namespace tcp

} //namespace net

} //namespace dlagon