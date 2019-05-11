#ifndef LZX_DLAGON_INTERFACE_RESPONSE_H_
#define LZX_DLAGON_INTERFACE_RESPONSE_H_

#include <string>

namespace lzx::dlagon::interface{
class Response{
   public:
      virtual const std::string ToString() const = 0;
      void SetBody(const std::string &str){
         body_ = str;
      }
      virtual ~Response(){}
   protected:
      std::string body_;
   };
}


#endif //LZX_DLAGON_INTERFACE_RESPONSE_H_