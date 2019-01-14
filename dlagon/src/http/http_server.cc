#include "http/http_server.h"

using dlagon::net::EndPoint;
using dlagon::net::tcp::TcpServerSocket;
using dlagon::net::tcp::TcpClientSocket;

namespace dlagon{
namespace http{
   void HttpServer::Bind(const int port){
      Bind(EndPoint(port));
   }
   void HttpServer::Bind(const EndPoint &endpoint){
      this->socket_.Bind(endpoint);
   }

   void HttpServer::Listen(const int queue_length){
      this->socket_.Listen(queue_length);
   }

   auto HttpServer::Accept()
      -> std::tuple<HttpClient, EndPoint>
   {
      using Result = std::tuple<TcpClientSocket, EndPoint>;

      Result result = this->socket_.Accept();
      HttpClient client{std::get<0>(result)};
      EndPoint endpoint = std::get<1>(result);
      return std::make_tuple(client, endpoint);
   }
} //namespace http
} //namespace dlagon