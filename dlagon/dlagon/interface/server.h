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

#include "dlagon/interface/request.h"
#include "dlagon/interface/response.h"
#include "dlagon/interface/handler.h"
#include "dlagon/interface/factory.h"
#include "dlagon/interface/net_adapter.h"

namespace lzx::dlagon::interface{


   //作为接口类, 
   class IServer{
   public:
      IServer(IProtocolObjectFactory *factory)
         : factory_(factory)
      {}

      void Run(int port){
         server_socket_->Bind(port);
         server_socket_->Listen(1024);
         INetClientSocketAdapter *client = server_socket_->Accept();
         // 转发到线程池中运行
         std::thread th{Work, client};
         th.detach();
      }

      virtual ~IServer();

   private:
      // 实际工作流程
      void Work(INetClientSocketAdapter *client){
         std::string str = client->Receviced();
         Request *req =  factory_->RequestFromString(str);
         Response *res = factory_->Response();

         Gateway(*req, *res);
         IHandler *handler = Route(*req);    // 禁止释放
         handler->Handle(*req, *res);
         const std::string result = res->ToString();
         client->Send(result);

         delete client;
         delete req;
         delete res;
      }
   private:
      // 需要重载的部分
      
      
      virtual void Gateway(Request &req, Response &res);
      virtual IHandler *Route(Request &req);             // 可以将Route修改为对象,
      
      // Handle函数移动到Ihandler类中
      //virtual void Handle(const Request &req, Response &res);


      
      // 下面的方法移动到Request和resposne中
      // virtual void UnSerialize(const std::string str, Request &req, Response &res) = 0;
      // virtual std::string Serialize(const Response &res) = 0;


      
      
      INetServerSocketAdapter *server_socket_;
      IProtocolObjectFactory *factory_;
   };

}

#endif //LZX_DLAGON_SERVER_SERVER_H_