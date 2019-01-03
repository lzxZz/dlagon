#ifndef DLAGON_SERVER_ROUTE_H_
#define DLAGON_SERVER_ROUTE_H_

#include <vector>

#include "server/handler.h"

namespace dlagon
{
   class Route;
   Handler DefaultRouter(const Route &route, dlagon::Path path);
   /**
    * Route类,用于实现将请求转发给具体的处理函数, 
    **/
   class Route  {
      using RouteFunction =  Handler(*)(const Route &route, dlagon::Path);
   friend Handler DefaultRouter(const Route &route, dlagon::Path path);
   public:
      Route(RouteFunction function)
         : function_(function) {}
      Route() {}
      
      // 用于执行分发的函数,多数情况下调用function_成员来进行操作
      Handler Distribute(dlagon::Path path);               
      // 给Path注册对应的处理函数
      Route &Register(dlagon::Path path, Handler hander);
      // 默认的分发函数
      
   private:
      
      RouteFunction function_ = DefaultRouter;     //默认路由函数
      Handler default_handlder_ = Handler::GetFile; //默认处理函数,用于所有路径的匹配失败的情况
      
      //成对的路径和处理函数
      std::vector<Path> paths_;           
      std::vector<Handler> handers_;
   
   };
   
   
} // dlagon




#endif // DLAGON_SERVER_ROUTE_H_
