/**
 * @file route.h
 * @author lzxZz (616281384@qq.com)
 * @brief 路由的抽象, 用于在中间件中实现路由功能
 * @version 0.1
 * @date 2019-05-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_INTERFACE_ROUTE_H_
#define LZX_DLAGON_INTERFACE_ROUTE_H_

#include "dlagon/interface/handler.h"
#include "dlagon/interface/protocol/request.h"
namespace lzx::dlagon::interface{
   class IRoute{
   public:
      // 根据请求返回对应的处理函数.
      virtual IHandler *Route(const Request &req) = 0;
      virtual ~IRoute(){}
   };
}


#endif //LZX_DLAGON_INTERFACE_ROUTE_H_