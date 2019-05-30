/**
 * @file request.h
 * @author lzxZz (616281384@qq.com)
 * @brief 请求
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_INTERFACE_REQUEST_H_
#define LZX_DLAGON_INTERFACE_REQUEST_H_

#include "dlagon/interface/protocol/body.h"
#include "dlagon/interface/protocol/argument.h"
#include "dlagon/interface/protocol/head.h"

namespace lzx::dlagon::interface{

   class Request{
   public:
      virtual ~Request(){}

   protected:
      ProtocolHead *head_ = nullptr;
      ProtocolBody *body_ = nullptr;
      Argument *argument_ = nullptr;

   };

}


#endif //LZX_DLAGON_INTERFACE_REQUEST_H_
