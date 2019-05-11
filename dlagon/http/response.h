#ifndef LZX_DLAGON_HTTP_RESPONSE_H_
#define LZX_DLAGON_HTTP_RESPONSE_H_

#include "dlagon/interface/response.h"

#include <string>


namespace lzx::dlagon::http{
   class HttpResponse : public lzx::dlagon::interface::Response{

   public:
      const std::string ToString() const override;
      void SetBody(const std::string &str){
         body_ = str;
      }
   
   };
}


#endif //LZX_DLAGON_HTTP_RESPONSE_H_