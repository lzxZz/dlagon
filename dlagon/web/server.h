#ifndef LZX_DLAGON_WEB_SERVER_H_
#define LZX_DLAGON_WEB_SERVER_H_

#include "dlagon/interface/server.h"
#include "dlagon/http/protocol_factory.h"
#include "dlagon/interface/midware.h"
#include "dlagon/net/tcp/tcp_socket.h"
namespace lzx::dlagon::web{
   class WebServer : public lzx::dlagon::interface::IServer{
   friend class WebServerBuilder;
   public:
      ~WebServer(){}
   private:
      WebServer(lzx::dlagon::interface::IProtocolObjectFactory *factory, lzx::dlagon::interface::INetServerSocketAdapter *server, lzx::dlagon::interface::Midware *midware) :IServer(factory, server, midware){}

   };
}


#endif //LZX_DLAGON_WEB_SERVER_H_