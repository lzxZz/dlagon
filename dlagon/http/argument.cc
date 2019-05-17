#include "dlagon/http/argument.h"

#include <string>

using lzx::dlagon::interface::Argument;
using lzx::dlagon::interface::ArgumentFactory;

using std::string;

namespace lzx::dlagon::http{

   bool operator==(const HttpArgument &lhs, const HttpArgument &rhs){
      return (lhs.args_ == rhs.args_);
   }
   bool operator!=(const HttpArgument &lhs, const HttpArgument &rhs){
      return !(lhs == rhs);
   }

   Argument *HttpArgumentFactory::FromString(const string &str){
      return new HttpArgument();
   }

   string HttpArgument::ToString(){
      return "";
   }

}
