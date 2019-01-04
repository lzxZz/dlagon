// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.4

/**
 * server/route.h的实现
**/
#include "server/route.h"


namespace dlagon
{
   //作为Route的友元函数来进行默认的分发
   Handler DefaultRouter(const Route &route, dlagon::Path path){
      
      for (size_t i = 0; i < route.paths_.size(); i++){  
         // TODO  暂时使用完全匹配, 后期考虑修改使用正则或者更加简单的方式
         if (path == route.paths_.at(i)){
            return route.handers_.at(i);
         }
      }
      return route.default_handlder_;
   }

   Route &Route::Register(Path path, Handler handler){
      paths_.push_back(path);
      handers_.push_back(handler);
      return *this;
   }

   Handler Route::Distribute(Path path){
      // 修改为调用函数指针
      return function_(*this, path);
   }


} // dlagon
