/**
 * @file argument.h
 * @author lzxZz (616281384@qq.com)
 * @brief HTTP参数表类, 
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_HTTP_ARGUMENT_H_
#define LZX_DLAGON_HTTP_ARGUMENT_H_

#include <map>
#include <set>
#include <string>

#include "dlagon/common/result.h"
#include "dlagon/interface/protocol/argument.h"


namespace lzx::dlagon::http{
   /**
    * @brief 工厂类
    * 
    */
   class HttpArgumentFactory : public lzx::dlagon::interface::ArgumentFactory{
   public:
      lzx::dlagon::interface::Argument *FromString(const std::string &str) override;
      // 增加一个参数行集合的作为参数的重载
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
   friend class HttpProtocolFactory; // TODO 应该由HttpProtocolFactory访问HttpArgumentFactory来构造参数对象.
   public:
      void Set(const std::string &key, const std::string &value){
         args_.emplace(std::make_pair(key, value));
      }
      

      const Result<std::string> Get(const std::string &key) const;
      const std::string ToString() const override;
   private:
      std::map<std::string, std::string> args_;
   };
}


#endif //LZX_DLAGON_HTTP_ARGUMENT_H_