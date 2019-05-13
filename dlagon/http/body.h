#ifndef LZX_DLAGON_HTTP_BODY_H_
#define LZX_DLAGON_HTTP_BODY_H_

#include "dlagon/interface/protocol/body.h"

namespace lzx::dlagon::http {

   class HttpResponseBody : public lzx::dlagon::interface::ProtocolBody{
   public:
      HttpResponseBody(const std::string &body) : body_(body) {}
      std::string ToString() override{
         
         return body_;
      }
   private:

      std::string body_;
   };

   
}


#endif //LZX_DLAGON_HTTP_BODY_H_