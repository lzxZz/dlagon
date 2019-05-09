#ifndef LZX_DLAGON_INTERFACE_NET_ADAPTER_H_
#define LZX_DLAGON_INTERFACE_NET_ADAPTER_H_

namespace lzx::dlagon::interface{
   class INetServerSocketAdapter{
   public:
      virtual void Bind(int port) = 0;
      virtual void Listen(int queue_length) = 0;
      virtual INetClientSocketAdapter *Accept() = 0;
   };
   class INetClientSocketAdapter{
   public:
      void Send(const std::string &str);
      std::string Receviced();
   };
    
}

#endif //LZX_DLAGON_INTERFACE_NET_ADAPTER_H_