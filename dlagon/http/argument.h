#ifndef LZX_DLAGON_HTTP_ARGUMENT_H_
#define LZX_DLAGON_HTTP_ARGUMENT_H_

#include <map>
#include <string>

#include "dlagon/interface/protocol/argument.h"

namespace lzx::dlagon::http{
   class HttpArgumentFactory : public lzx::dlagon::interface::ArgumentFactory{
   public:
      lzx::dlagon::interface::Argument *FromString(const std::string &str) override;
   };
   class HttpArgument : public lzx::dlagon::interface::Argument{
   friend bool operator==(const HttpArgument &lhs, const HttpArgument &rhs);
   friend bool operator!=(const HttpArgument &lhs, const HttpArgument &rhs);
   public:
      void Set(const std::string &key, const std::string &value);
      void Get(const std::string &key, std::string &value);
      std::string ToString() override;
   private:
      std::map<std::string, std::string> args_;
   };
}


#endif //LZX_DLAGON_HTTP_ARGUMENT_H_