// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.4

/*
    本文件声明的Route类,用于表示一个路由组件,将请求发送给具体的Handler来处理
    默认使用全路径匹配来进行路由,匹配失败会调用默认的处理函数.
    
*/
#ifndef DLAGON_SERVER_ROUTE_H_
#define DLAGON_SERVER_ROUTE_H_

#include <vector>

#include "server/handler.h"

namespace dlagon
{
   // 前置声明,用于声明外部函数
   class Route;
   
   // 默认路由函数,由于需要访问Route的非静态数据,因此不能使Route类的静态函数.
   Handler DefaultRouter(const Route &route, dlagon::Path path);
   /**
    * Route类,用于实现将请求转发给具体的处理函数, 
    **/
   class Route  {
      using RouteFunction =  Handler(*)(const Route &route, dlagon::Path);
   // 声明默认路由函数为友元函数,来允许访问私有数据
   friend Handler DefaultRouter(const Route &route, dlagon::Path path);
   public:
      // 传入自定义的路由函数来替代默认的路由函数
      Route(RouteFunction function)
         : function_(function) {}
      
      Route() {} 
      
      // 用于执行分发的函数,调用function_成员来进行操作
      Handler Distribute(const dlagon::Path &path);               
      // 给Path注册对应的处理函数
      Route &Register(dlagon::Path path, Handler hander);
      
      
   private:
      
      RouteFunction function_ = DefaultRouter;     //默认路由函数
      Handler default_handlder_ = Handler::GetFile; //默认处理函数,用于所有路径的匹配失败的情况
      
      //成对的路径和处理函数
      std::vector<Path> paths_;           
      std::vector<Handler> handers_;
   
   };
   
   
} // dlagon




#endif // DLAGON_SERVER_ROUTE_H_
