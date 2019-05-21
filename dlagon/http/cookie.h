/**
 * @file cookie.h
 * @author lzxZz (616281384@qq.com)
 * @brief 用于HTTP的cookie声明
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef  LZX_DLAGON_HTTP_COOKIE_H_
#define  LZX_DLAGON_HTTP_COOKIE_H_

#include <string>

namespace lzx::dlagon::http{
   class Cookie{
   
   public:
      Cookie(const std::string &name, std::string &value)
         : name_ (name), value_(value)
      {}

   private:

      std::string name_;
      std::string value_;
      std::string expire_;
      std::string time_;
      std::string domain_;
      std::string path_;
      bool secure_;
      bool http_only_;

   };
}


#endif //LZX_DLAGON_HTTP_COOKIE_H_