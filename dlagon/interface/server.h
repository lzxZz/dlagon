/**
 * @file server.h
 * @author lzx (616281384@qq.com)
 * @brief 服务的基本框架, 
 * >>>>>> 用户禁止修改 <<<<<<
 * @version 0.1
 * @date 2019-04-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#ifndef LZX_DLAGON_SERVER_SERVER_H_
#define LZX_DLAGON_SERVER_SERVER_H_

#include <string>
#include <thread>

#include "dlagon/common/log.h"
#include "dlagon/interface/midware.h"
#include "dlagon/interface/net_adapter.h"
#include "dlagon/interface/handler.h"
#include "dlagon/interface/protocol/factory.h"
#include "dlagon/interface/protocol/request.h"
#include "dlagon/interface/protocol/response.h"
#include "dlagon/interface/route.h"



namespace lzx::dlagon::interface{


   //作为接口类, 
   class IServer{
   public:
      IServer(IProtocolObjectFactory *factory, INetServerSocketAdapter *server, Midware *midware)
         : factory_(factory), server_socket_(server), midware_(midware)
      {}
      
      // IServer() = delete; // 保留默认构造函数, 用于工厂构造.
      
      /**
       * @brief 用户使用的唯一程序, 其作用为绑定本地任意ip的端口,并开始监听,处理
       * 
       * @param port 
       */
      void Run(int port){
         server_socket_->Bind(port);
         server_socket_->Listen(1024);         
         for (;;){
            INetClientSocketAdapter *client = server_socket_->Accept();
            // TODO 转发到线程池中运行
            std::thread th(Work, this,  client);
            th.detach();            
         }         
      }

      virtual ~IServer(){}

   private:
      // 实际工作流程
      static void Work(IServer *self, INetClientSocketAdapter *client){
         // 获取请求
         std::string str = client->Receviced();
         Request *req =  self->factory_->RequestFromString(str);
         Response *res = self->factory_->GetResponse();
         
         // 调用中间件, 开始处理请求
         self->midware_->Handle(*req, *res);

         //返回响应
         const std::string result = res->ToString();
         client->Send(result);

         delete client;
         delete req;
         delete res;
      }
      
   protected:      
      IProtocolObjectFactory *factory_ ;
      INetServerSocketAdapter *server_socket_ ;
      Midware *midware_;
   };
}

#endif //LZX_DLAGON_SERVER_SERVER_H_