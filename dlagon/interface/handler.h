/**
 * @file handler.h
 * @author lzxZz (616281384@qq.com)
 * @brief 请求处理的抽象.
 * @version 0.1
 * @date 2019-05-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_SERVER_HANDLER_H_
#define LZX_DLAGON_SERVER_HANDLER_H_

#include "dlagon/interface/protocol/request.h"
#include "dlagon/interface/protocol/response.h"

namespace lzx::dlagon::interface{

class IHandler{
   public:
      virtual void Handle(Request &req, Response &res) = 0;
      virtual ~IHandler(){}
   };

}

#endif //LZX_DLAGON_SERVER_HANDLER_H_