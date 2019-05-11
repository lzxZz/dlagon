#ifndef LZX_DLAGON_WEB_SERVER_H_
#define LZX_DLAGON_WEB_SERVER_H_

#include "dlagon/interface/server.h"
#include "dlagon/http/factory.h"
namespace lzx::dlagon::web{
   class WebServer : public lzx::dlagon::interface::IServer{
   friend class WebServerBuilder;
   public:
      WebServer() : IServer{lzx::dlagon::http::HttpProtocolFactory::GetInstant(), nullptr}
      {}

   };
}


#endif //LZX_DLAGON_WEB_SERVER_H_