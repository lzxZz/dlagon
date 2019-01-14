// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.9

/*
   定义了Cookie类,并支持了六个属性,对Expires进行了单独的实现,使用了rfc1123的日期格式
*/

#ifndef DLAGON_HTTP_COOKIE_H_
#define DLAGON_HTTP_COOKIE_H_

#include <string>

namespace dlagon{

namespace http{

   class Cookie{
   public:
      Cookie(const std::string &name, const std::string &value)
         : name_(name), value_(value)  {}
      
      const std::string ToString();

      Cookie &SetMaxAge(const int max_age);
      Cookie &SetExpires(const int year, const int month, const int day);
      Cookie &SetDomain(const std::string &domain);
      Cookie &SetPath(const std::string &path);
      Cookie &SetSecure(const bool secure);
      Cookie &SetHttpOnly(const bool only);

      std::string MaxAge();
      std::string Expires();
      std::string Domain();
      std::string Path();
      std::string Secure();
      std::string HttpOnly();
      const std::string Name(){
         return name_;
      }
      const std::string Value(){
         return value_;
      }
      static const char *Days(int, int, int);
   private:
      std::string name_ = "";
      std::string value_ ="";

      std::string expires_="";   //wkday "," SP date1 SP time SP "GMT" 
                              // wkday = Mon, Tue, Wed, Thu, Fri, Sat, Sun
                              // date1 = 2Digit SP month 4Digit   02 Jun 1982
                              // month = Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
                              
      int max_age_ = 0;
      std::string domain_ = "";
      std::string path_ ="";
      bool secure_ = false;
      bool http_only_ = false;
   };

} //namespace http
} //namespace dlagon

#endif //DLAGON_HTTP_COOKIE_H_