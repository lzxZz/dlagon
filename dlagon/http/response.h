#ifndef LZX_DLAGON_HTTP_RESPONSE_H_
#define LZX_DLAGON_HTTP_RESPONSE_H_
/**
 * @file response.h
 * @author lzxZz (616281384@qq.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "dlagon/interface/protocol/response.h"

#include <string>

#include "dlagon/http/body.h"

namespace lzx::dlagon::http{
   class HttpResponse : public lzx::dlagon::interface::Response{

   public:
      const std::string ToString() const override;
      void SetBody(const std::string &str){
         body_ = new HttpResponseBody(str);
      }
   
   };
}


#endif //LZX_DLAGON_HTTP_RESPONSE_H_