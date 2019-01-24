// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.28

/*
    本文件声明异常基类,
    目前作为HTTP请求头的组成部分.
*/

#ifndef DLAGON_EXCEPTION_EXCEPTION_H_
#define DLAGON_EXCEPTION_EXCEPTION_H_

#include <string>

namespace dlagon{
   namespace exception{
      /**
       * 
       *    异常基类.
       * 
       *    虚函数What()用于输出异常信息.
       * 
      **/
      class Exception{
      public:
         Exception(const std::string &info) 
            : information_(info) {}
         Exception(const char *info) 
            : information_(info) {}
         virtual ~Exception() {} 
         virtual auto What() const
            ->  const std::string 
         {
            return information_;
         }
      private:
         const std::string information_;
      };

   } //namespace exception
} //namespace dlagon



#endif //DLAGON_EXCEPTION_EXCEPTION_H_