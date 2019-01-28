// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.5

/**
 * http/mime_type.h的实现
**/
#include "http/mime_type.h"
#include "common/debug.h"

using std::string;
namespace dlagon
{

namespace http
{
   const string MimeType::SuffixToMimeType(string suffix){
        DLAGON_CALL_DEBUG;
      for (auto &c : suffix){
         c = toupper(c);
      }

      if (suffix == "HTML" || suffix == "HTM"){
         return "text/html";
      } else if (suffix == "CSS"){
         return "test/css";
      } else if (suffix == "JS"){
         return "application/x-javascript";
      } 
      // 匹配后缀失败的返回普通文本
      return "text/plain";

   }


} // http

} // dlagon
