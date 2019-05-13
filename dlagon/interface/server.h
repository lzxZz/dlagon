/**
 * @file server.h
 * @author lzx (616281384@qq.com)
 * @brief 服务的基本结构
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

#include "dlagon/interface/protocol/request.h"
#include "dlagon/interface/protocol/response.h"
#include "dlagon/interface/handler.h"
#include "dlagon/interface/protocol/factory.h"
#include "dlagon/interface/net_adapter.h"
#include "dlagon/interface/route.h"
#include "dlagon/interface/midware.h"

#include <iostream>
using std::cout;
using std::endl;

namespace lzx::dlagon::interface{


   //作为接口类, 
   class IServer{
   public:
      IServer(IProtocolObjectFactory *factory, INetServerSocketAdapter *server, Midware *midware)
         : factory_(factory), server_socket_(server), midware_(midware)
      {}
      
      // IServer() = delete;

      void Run(int port){
         
         server_socket_->Bind(port);
         
         server_socket_->Listen(1024);
         
         for (;;){
            INetClientSocketAdapter *client = server_socket_->Accept();
            
            // 转发到线程池中运行
            std::thread th(Work, this,  client);
            
            th.detach();
            
         }
         
      }

      virtual ~IServer(){}

   private:
      // 实际工作流程
      static void Work(IServer *self, INetClientSocketAdapter *client){
         
         std::string str = client->Receviced();
         Request *req =  self->factory_->RequestFromString(str);
         Response *res = self->factory_->GetResponse();
         
         // self->Gateway(*req, *res);
         // IHandler *handler = self->route_->Route(*req);    // 禁止释放
         // handler->Handle(*req, *res);
         self->midware_->Handler(*req, *res);

         const std::string result = res->ToString();
         client->Send(result);

         delete client;
         delete req;
         delete res;
      }
   private:
      // 需要重载的部分
      
      
      // virtual void Gateway(Request &req, Response &res){}
      // virtual IHandler *Route(Request &req);             //将Route修改为对象,
      
      // Handle函数移动到Ihandler类中
      //virtual void Handle(const Request &req, Response &res);


      
      // 下面的方法移动到Request和resposne中
      // virtual void UnSerialize(const std::string str, Request &req, Response &res) = 0;
      // virtual std::string Serialize(const Response &res) = 0;


      
   protected:
      
      IProtocolObjectFactory *factory_ ;
      INetServerSocketAdapter *server_socket_ ;
      Midware *midware_;
      
      // static IRoute *route_ ;
   };

}

#endif //LZX_DLAGON_SERVER_SERVER_H_