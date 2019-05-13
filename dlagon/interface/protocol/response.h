#ifndef LZX_DLAGON_INTERFACE_RESPONSE_H_
#define LZX_DLAGON_INTERFACE_RESPONSE_H_

#include <string>
#include "dlagon/interface/protocol/argument.h"
#include "dlagon/interface/protocol/body.h"
#include "dlagon/interface/protocol/head.h"
#include "dlagon/interface/protocol/argument.h"

namespace lzx::dlagon::interface{

   class Response{
   public:
      virtual const std::string ToString() const = 0;
      void SetBody(ProtocolBody *body){
         body_ = body;
      }
      virtual ~Response(){}
   protected:
      ProtocolBody *body_;
      ProtocolHead *head_;
      Argument *argument_;
   };
}


#endif //LZX_DLAGON_INTERFACE_RESPONSE_H_