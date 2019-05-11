#include "dlagon/http/protocol_factory.h"

#include "dlagon/http/request.h"
#include "dlagon/http/response.h"

using lzx::dlagon::interface::Request;
using lzx::dlagon::interface::Response;
using lzx::dlagon::interface::IProtocolObjectFactory;

namespace lzx::dlagon::http{
   HttpProtocolFactory *HttpProtocolFactory::factory_ = nullptr;

   Request *HttpProtocolFactory::RequestFromString(const std::string &str) {
      return new HttpRequest();
   }

   Response *HttpProtocolFactory::GetResponse(){
      return new HttpResponse();
   }

   IProtocolObjectFactory *HttpProtocolFactory::GetInstant(){
      if (factory_ == nullptr){
         factory_  = new HttpProtocolFactory();
      }
      return factory_;
   }
}