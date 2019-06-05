#include "dlagon/net/tcp/tcp_socket.h"


#include <string>
#include <unistd.h>
#include <arpa/inet.h>


#include <iostream>
using std::cout;
using std::endl;

#include "dlagon/error/exception.h"
#include "dlagon/error/panic.h"
#include "dlagon/net/end_point.h"

using std::string;
using lzx::dlagon::interface::INetClientSocketAdapter;
using lzx::dlagon::error::Panic;
namespace lzx::dlagon::net::tcp{
   void TcpServerSocket::Bind(int port){
      EndPoint end_point{port};
      int status = bind(FD(), end_point.ScoketAddress(), end_point.Size());
      if (status != 0){
         // throw lzx::dlagon::exception::Exception(string{strerror(status)});
         Panic(strerror(errno));
      }
   }

   void TcpServerSocket::Listen(int queue_length){
      int status = listen(FD(), queue_length);
      if (status != 0){
         // throw lzx::dlagon::exception::Exception(string{strerror(status)});
         Panic(strerror(errno));
      }
   }

   INetClientSocketAdapter *TcpServerSocket::Accept(){
      using SA = struct sockaddr;
      struct sockaddr_in addr;
      int fd;
      socklen_t len = sizeof(addr);
      fd = accept(this->FD(), (SA *)&addr, &len);

      // TODO 完善client的构造函数
      if (fd == -1){
         throw lzx::dlagon::exception::Exception("调用Accept失败, 返回了错误的文件描述符");
      }else{
         TcpClientSocket *client = new TcpClientSocket{fd, EndPoint{addr}};
         return client;
      }
      

      
   }

   void TcpClientSocket::Send(const string &str){
      write(this->FD(), str.c_str(), str.size());
   }

   string TcpClientSocket::Receviced(){
      string content;

      char *buf = new char[BUFSIZ];
      size_t n = 0;
      do{
         n = read(this->FD(), buf, BUFSIZ);      // 2018.12.26修改为read函数
         
         content.append(buf, n);
      }while(n == BUFSIZ);
      delete[] buf;
      cout << content << endl;
      return content;
   }

   bool TcpClientSocket::Connect(){
      connect(this->FD(), end_point_.ScoketAddress(), end_point_.Size());
      return true;
   }



}