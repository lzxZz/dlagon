#ifndef LZX_DLAGON_INTERFACE_REQUEST_H_
#define LZX_DLAGON_INTERFACE_REQUEST_H_

#include "dlagon/interface/protocol/head.h"
#include "dlagon/interface/protocol/body.h"
#include "dlagon/interface/protocol/argument.h"


namespace lzx::dlagon::interface{

   class Request{
   public:
      virtual ~Request(){}

   protected:
      ProtocolHead *head_ = nullptr;
      ProtocolBody *body_ = nullptr;

   };

}


#endif //LZX_DLAGON_INTERFACE_REQUEST_H_
