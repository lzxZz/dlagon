#ifndef LZX_DLAGON_WEB_FACROEY_H_
#define LZX_DLAGON_WEB_FACROEY_H_

#include "dlagon/web/server.h"
#include "dlagon/interface/route.h"
#include "dlagon/interface/net_adapter.h"
#include "dlagon/interface/factory.h"

namespace lzx::dlagon::web{
   class WebServerBuilder{
      WebServer *GetWebServer();
      void SetRoute(lzx::dlagon::interface::IRoute *route);
      void SetServerSocket(lzx::dlagon::interface::INetServerSocketAdapter *server);
      void SetProtocolFactory(lzx::dlagon::interface::IProtocolObjectFactory *factory);
      WebServerBuilder *GetInstant();
   };
}

#endif //LZX_DLAGON_WEB_FACROEY_H_