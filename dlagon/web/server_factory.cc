#include "dlagon/web/server_factory.h"

using lzx::dlagon::web::WebServerBuilder;




namespace lzx::dlagon::web{
   WebServerBuilder *WebServerBuilder::builder_ = nullptr;
   

   WebServerBuilder *WebServerBuilder::GetInstant(){
      if (builder_ == nullptr){
         builder_ = new WebServerBuilder();
      }
      
      return builder_;
   }
   // using lzx::dlagon::interface::IProtocolObjectFactory;
   // using lzx::dlagon::interface::INetServerSocketAdapter;
   WebServer *WebServerBuilder::GetWebServer(){
      WebServer *web_server = nullptr;
      web_server = new WebServer(factory_, server_, midware_);
      factory_ = nullptr;
      server_ = nullptr;
      midware_ = nullptr;

      return web_server;
   }

   void WebServerBuilder::SetMidware(lzx::dlagon::interface::Midware *midware){
      midware_ = midware;
   }
   void WebServerBuilder::SetServerSocket(lzx::dlagon::interface::INetServerSocketAdapter *server){
      server_ = server;
   }
   void WebServerBuilder::SetProtocolFactory(lzx::dlagon::interface::IProtocolObjectFactory *factory){
      factory_ = factory;
   }

}