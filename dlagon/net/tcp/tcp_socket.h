#ifndef LZX_DLAGON_NET_TCP_SOCKET_H_
#define LZX_DLAGON_NET_TCP_SOCKET_H_

#include "dlagon/interface/net_adapter.h"
#include "dlagon/net/socket.h"

namespace lzx::dlagon::net::tcp{

   class TcpServerSocket : public Socket, public lzx::dlagon::interface::INetServerSocketAdapter{
   public:
      TcpServerSocket() : Socket{Socket::New()}{

      }
      void Bind(int port) override;
      void Listen(int queue_length) override;
      lzx::dlagon::interface::INetClientSocketAdapter *Accept() override;
   };

   class TcpClientSocket : public Socket, public lzx::dlagon::interface::INetClientSocketAdapter{
   public:
      void Send(const std::string &str) override;
      std::string Receviced() override;
      bool Connect() override;
      TcpClientSocket(int fd, EndPoint end_point) : Socket{fd}, end_point_(end_point){}
   private:
      EndPoint end_point_;
   };

}

#endif //LZX_DLAGON_NET_TCP_SOCKET_H_