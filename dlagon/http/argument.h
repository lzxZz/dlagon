#ifndef LZX_DLAGON_HTTP_ARGUMENT_H_
#define LZX_DLAGON_HTTP_ARGUMENT_H_

#include <map>
#include <string>
#include <set>

#include "dlagon/interface/protocol/argument.h"
#include "dlagon/common/result.h"

namespace lzx::dlagon::http{
   class HttpArgumentFactory : public lzx::dlagon::interface::ArgumentFactory{
   public:
      lzx::dlagon::interface::Argument *FromString(const std::string &str) override;
      lzx::dlagon::interface::Argument *FromString(const std::set<std::string> &str);
      static HttpArgumentFactory *GetInstant(){
         if (factory_ ==  nullptr){
            factory_ = new HttpArgumentFactory();
         }
         return factory_;
      }
   private:
      static HttpArgumentFactory *factory_;
   };


   class HttpArgument : public lzx::dlagon::interface::Argument{
   friend bool operator==(const HttpArgument &lhs, const HttpArgument &rhs);
   friend bool operator!=(const HttpArgument &lhs, const HttpArgument &rhs);
   friend class HttpArgumentFactory;
   friend class HttpProtocolFactory;
   public:
      void Set(const std::string &key, const std::string &value){
         args_.emplace(std::make_pair(key, value));
      }
      // bool Get(const std::string &key, std::string &value);
      Result<std::string> Get(const std::string &key);
      std::string ToString() override;
   private:
      std::map<std::string, std::string> args_;
   };
}


#endif //LZX_DLAGON_HTTP_ARGUMENT_H_