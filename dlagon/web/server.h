#ifndef LZX_DLAGON_WEB_SERVER_H_
#define LZX_DLAGON_WEB_SERVER_H_

#include "dlagon/interface/server.h"
#include "dlagon/http/protocol_factory.h"
namespace lzx::dlagon::web{
   class WebServer : public lzx::dlagon::interface::IServer{
   friend class WebServerBuilder;
   public:
      ~WebServer(){}
   private:
      WebServer() :IServer(){}

   };
}


#endif //LZX_DLAGON_WEB_SERVER_H_