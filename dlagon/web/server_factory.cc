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

   WebServer *WebServerBuilder::GetWebServer(){
      return web_server_;
   }

   void WebServerBuilder::SetRoute(lzx::dlagon::interface::IRoute *route){
      web_server_->route_ = route;
   }
   void WebServerBuilder::SetServerSocket(lzx::dlagon::interface::INetServerSocketAdapter *server){
      web_server_->server_socket_ = server;
   }
   void WebServerBuilder::SetProtocolFactory(lzx::dlagon::interface::IProtocolObjectFactory *factory){
      web_server_->factory_ = factory;
   }

}