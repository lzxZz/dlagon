#include "dlagon/http/request.h"

namespace lzx::dlagon::http{
   bool operator==(const HttpRequest &lhs, const HttpRequest &rhs){
      return (*(dynamic_cast<HttpRequestHead*>(lhs.head_)) == *(dynamic_cast<HttpRequestHead*>(rhs.head_))&&
           *(dynamic_cast<HttpRequestBody*>(lhs.body_)) == *(dynamic_cast<HttpRequestBody*>(rhs.body_)) &&
           *(lhs.argument_) == *(rhs.argument_));
   }
   bool operator!=(const HttpRequest &lhs, const HttpRequest &rhs){
      return !(lhs == rhs);
   }

}