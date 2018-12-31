#ifndef DLAGON_HTTP_CLIENT_H_
#define DLAGON_HTTP_CLIENT_H_

#include "net/tcp/tcp_client_socket.h"
#include "http/http_response.h"
#include "http/http_request.h"

namespace dlagon{
namespace http{
   class HttpClient{
   public:
      HttpClient(){}
      HttpClient(const int fd)
         : socket_(fd) {}
      HttpClient(dlagon::net::tcp::TcpClientSocket &sock)
         : socket_(sock.PointerFD()) {}

      void Send(const std::string &str);
      void Send(const HttpResponse response);
      std::string Recevie();
      HttpRequest GetRequest();
      
   private:
      dlagon::net::tcp::TcpClientSocket socket_;
   };

} //namespace http
} //namespace dlagon
#endif //DLAGON_HTTP_CLIENT_H_