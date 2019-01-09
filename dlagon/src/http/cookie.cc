// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.9

/*
   对hhtp/cookie.h的实现.
*/

#include "http/cookie.h"

using std::string;

namespace dlagon{

namespace http{

   // 判断闰年
   int IsLeapYear(int year){
      if (year % 400 == 0){
         return 1;
      }else if (year % 100 == 0){
         return 0;
      }else if (year % 4 == 0){
         return 1;
      }

      return 0;
   }

   int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
   char wk_days[7][4] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
   char mon_str[12][4] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
   
   //获取指定日期是星期几
   const char *GetWkDay(int year, int month, int day){
      int sum = day;

      for (int i = 0; i < month -1; i++){
         sum += days[i];
      }
      if (month > 2){
         sum += IsLeapYear(year);
      }
      
      int days = (year - 1) * 365 + sum;

      for (int i = year - 1; i >= 0; i--){
         days += IsLeapYear(i);
      }
      days--;
      return wk_days[days % 7];
      
   }


   // 用于测试的函数
   const char *Cookie::Days(int y, int m , int d){
      return GetWkDay(y,m,d);
   }

   // 在指定过期日期的时候,强制设置时间为00:00:00
   Cookie &Cookie::SetExpires(int year, int month, int day){
      expires_ = GetWkDay(year, month, day);
      expires_.append(", ");
      if (day < 10){
         expires_.append("0");
      }
      expires_.append(std::to_string(day));
      expires_.append(" ");
      expires_.append(mon_str[month -1]);
      expires_.append(" ");
      expires_.append(std::to_string(year));
      expires_.append(" 00:00:00 GMT");

      return *this;
   }

   Cookie &Cookie::SetMaxAge(int max_age){
      max_age_ = max_age;
      return *this;
   }

   Cookie &Cookie::SetDomain(string domain){
      domain_ = domain;
      return *this;
   }

   Cookie &Cookie::SetPath(string path){
      path_ = path;
      return *this;
   }

   Cookie &Cookie::SetSecure(bool secure){
      secure_ = secure;
      return *this;
   }

   Cookie &Cookie::SetHttpOnly(bool http_only){
      http_only_ = http_only;
      return *this;
   }


   string Cookie::Expires(){
      return expires_;
   }

   string Cookie::MaxAge(){
      return std::to_string(max_age_);
   }

   
   string Cookie::Domain(){
      return domain_;
   }

   string Cookie::Path(){
      return path_;
   }

   string Cookie::Secure(){
      return std::to_string(secure_);
   }

   string Cookie::HttpOnly(){
      return std::to_string(http_only_);
   }
   
   const string Cookie::ToString(){
      string header = "Set-Cookie: ";
      header.append(name_);
      header.append("=");
      header.append(value_);
      if (max_age_ != 0){
         header.append(" ; Max-Age=");
         header.append(std::to_string(max_age_));
      }
      if (expires_ != ""){
         header.append(" ; Expires=");
         header.append(expires_);
      } 
      if (domain_ != ""){
         header.append(" ; Domain=");
         header.append(domain_);
      }
      if (path_ != ""){
         header.append(" ; Path=");
         header.append(path_);
      }
      if (secure_){
         header.append(" ; Secure");
      } 
      if (http_only_){
         header.append(" ; HttpOnly");
      }
      return header;
   }

} //namespace http

} //namespace dlagon