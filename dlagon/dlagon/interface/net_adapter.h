#ifndef LZX_DLAGON_INTERFACE_NET_ADAPTER_H_
#define LZX_DLAGON_INTERFACE_NET_ADAPTER_H_

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
      void Send(const std::string &str);
      std::string Receviced();
      virtual ~INetClientSocketAdapter(){}
   };
    
}

#endif //LZX_DLAGON_INTERFACE_NET_ADAPTER_H_