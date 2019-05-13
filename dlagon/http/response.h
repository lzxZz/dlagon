#ifndef LZX_DLAGON_HTTP_RESPONSE_H_
#define LZX_DLAGON_HTTP_RESPONSE_H_

#include "dlagon/interface/protocol/response.h"

#include <string>

#include "dlagon/http/body.h"

namespace lzx::dlagon::http{
   class HttpResponse : public lzx::dlagon::interface::Response{

   public:
      const std::string ToString() const override;
      void SetBody(const std::string &str){
         body_ = new HttpResponseBody(str);
      }
   
   };
}


#endif //LZX_DLAGON_HTTP_RESPONSE_H_