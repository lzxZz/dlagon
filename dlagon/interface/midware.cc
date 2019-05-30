/**
 * @file midware.cc
 * @author lzxZz (616281384@qq.com)
 * @brief 中间件的定义, 使用职责链设计模式
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "dlagon/interface/midware.h"
#include "dlagon/interface/protocol/request.h"
#include "dlagon/interface/protocol/response.h"


namespace lzx::dlagon::interface{
   void Midware::WorkFlow(const Request &req, Response &res){
      MidwareState state =  Handler(req, res);

      // 判断链是否继续调用
      if (state == MidwareState::kContinue){
         if (next_){
            next_->Handler(req, res);
         }
      }
   }
}