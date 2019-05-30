/**
 * @file response.h
 * @author lzxZz (616281384@qq.com)
 * @brief 响应
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_INTERFACE_RESPONSE_H_
#define LZX_DLAGON_INTERFACE_RESPONSE_H_

#include <string>

#include "dlagon/interface/protocol/argument.h"
#include "dlagon/interface/protocol/body.h"
#include "dlagon/interface/protocol/head.h"


namespace lzx::dlagon::interface{

   class Response{
   public:
      virtual const std::string ToString() const = 0;
      void SetBody(ProtocolBody *body){
         body_ = body;
      }
      virtual ~Response(){}
   protected:
      Response(){}
      ProtocolBody *body_ = nullptr;
      ProtocolHead *head_ = nullptr;
      Argument *argument_ = nullptr;
   };
}


#endif //LZX_DLAGON_INTERFACE_RESPONSE_H_