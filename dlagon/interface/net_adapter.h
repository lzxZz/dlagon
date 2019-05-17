/**
 * @file net_adapter.h
 * @author lzxZz (616281384@qq.com)
 * @brief 网络模块适配器声明
 * @version 0.1
 * @date 2019-05-15
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef LZX_DLAGON_INTERFACE_NET_ADAPTER_H_
#define LZX_DLAGON_INTERFACE_NET_ADAPTER_H_

#include <string>

namespace lzx::dlagon::interface{
   class INetClientSocketAdapter;
   class INetServerSocketAdapter{
   public:
      virtual void Bind(int port) = 0;
      virtual void Listen(int queue_length) = 0;
      virtual INetClientSocketAdapter *Accept() = 0;
      virtual ~INetServerSocketAdapter(){}
   };
   class INetClientSocketAdapter{
   public:
      virtual void Send(const std::string &str) = 0;
      virtual std::string Receviced() = 0;
      virtual bool Connect() = 0;
      virtual ~INetClientSocketAdapter(){}
   };
    
}

#endif //LZX_DLAGON_INTERFACE_NET_ADAPTER_H_