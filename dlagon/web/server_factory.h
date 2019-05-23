/**
 * @file server_factory.h
 * @author lzxZz (616281384@qq.com)
 * @brief web服务的构造工厂
 * @version 0.1
 * @date 2019-05-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_WEB_FACROEY_H_
#define LZX_DLAGON_WEB_FACROEY_H_

#include "dlagon/web/server.h"
#include "dlagon/interface/route.h"
#include "dlagon/interface/net_adapter.h"
#include "dlagon/interface/protocol/factory.h"

namespace lzx::dlagon::web{
   class WebServerBuilder{
   public:
      WebServer *GetWebServer();
      // void SetRoute(lzx::dlagon::interface::IRoute *route);
      void SetMidware(lzx::dlagon::interface::Midware *midware);
      void SetServerSocket(lzx::dlagon::interface::INetServerSocketAdapter *server);
      void SetProtocolFactory(lzx::dlagon::interface::IProtocolObjectFactory *factory);
      // void Init(){
      //    web_server_ = new WebServer();
      // }
      static WebServerBuilder *GetInstant();
   private:
      WebServerBuilder(){}
      static WebServerBuilder *builder_;
      // WebServer *web_server_ = nullptr;
      lzx::dlagon::interface::IProtocolObjectFactory *factory_ = nullptr;
      lzx::dlagon::interface::INetServerSocketAdapter *server_ = nullptr;
      lzx::dlagon::interface::Midware *midware_ = nullptr;
   };
}

#endif //LZX_DLAGON_WEB_FACROEY_H_