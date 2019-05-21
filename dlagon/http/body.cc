#include "dlagon/http/body.h"

namespace lzx::dlagon::http{
   bool operator==(const HttpRequestBody &lhs, const HttpRequestBody &rhs){
      return (lhs.body_ == rhs.body_);
   }
   bool operator!=(const HttpRequestBody &lhs, const HttpRequestBody &rhs){
      return !(lhs == rhs);
   }
}