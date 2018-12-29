#ifndef DLAGON_NET_COMMON_UDP_SOCKET_H_
#define DLAGON_NET_COMMON_UDP_SOCKET_H_

#include "net/common/socket.h"


namespace dlagon{

namespace net{

   class UdpSocket : public Socket{
   public:
      UdpSocket(int fd)
         : Socket(fd) {}
      UdpSocket()
         : Socket(Socket::New(SocketFamily::IPv4, 
                              SocketType::DGRAM, 
                              SocketProtocolType::UDP)) {}
      // static UdpSocket New();
      void Bind(int port);
      void SendTo(const EndPoint endpoint,const std::string &str);
      auto ReceiveFrom()
         -> std::tuple<EndPoint, std::string>;
   
   };


} //namespace net

} //namespace dlagon

#endif //DLAGON_NET_COMMON_UDP_SOCKET_H_