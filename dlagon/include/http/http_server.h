#ifndef DLAGON_HTTP_SETVER_H_
#define DLAGON_HTTP_SETVER_H_

#include "net/tcp/tcp_server_socket.h"
#include "http/http_client.h"


namespace dlagon{
namespace http{

class HttpServer{
   
public:
   HttpServer()
      : socket_() {}
   
   void Bind(int port = 8080);
   void Bind(dlagon::net::EndPoint endpoint);
   void Listen(int queue_length = 1024);
   auto Accept()
      -> std::tuple<HttpClient, dlagon::net::EndPoint>;

private:
   dlagon::net::tcp::TcpServerSocket socket_;
};



} //namespace net
} //namespace dlagon

#endif //DLAGON_HTTP_SETVER_H_