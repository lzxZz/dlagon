#include "dlagon/net/tcp/tcp_socket.h"


#include <string>
#include <unistd.h>
#include <arpa/inet.h>


#include "dlagon/net/end_point.h"

using std::string;
using lzx::dlagon::interface::INetClientSocketAdapter;

namespace lzx::dlagon::net::tcp{
   void TcpServerSocket::Bind(int port){
      EndPoint end_point{port};
      bind(FD(), end_point.ScoketAddress(), end_point.Size());
   }

   void TcpServerSocket::Listen(int queue_length){
      listen(FD(), queue_length);
   }

   INetClientSocketAdapter *TcpServerSocket::Accept(){
      using SA = struct sockaddr;
      struct sockaddr_in addr;
      int fd;
      socklen_t len = sizeof(addr);
      fd = accept(this->FD(), (SA *)&addr, &len);

      // TODO 完善client的构造函数

      TcpClientSocket *client = new TcpClientSocket{fd, EndPoint{addr}};

      return client;
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
      return content;
   }

   bool TcpClientSocket::Connect(){
      connect(this->FD(), end_point_.ScoketAddress(), end_point_.Size());
      return true;
   }



}