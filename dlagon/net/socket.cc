#include "dlagon/net/socket.h"

namespace lzx::dlagon::net{
   void Socket::release_socket(const int* const fd){
      // std::cout << "---------xigou----------\n";    
      close(*fd);
      //    string info = "Close 套接字描述符失败\n要关闭的描述符为 : ";
      //    info.append(std::to_string(*fd));
      //    info.append("\n错误消息为 : ");
      //    info.append(strerror(errno));
      //    throw exception::Exception{info};
      // }
   }

   Socket Socket::New(SocketFamily family, 
                        SocketType type, 
                        SocketProtocolType protocol){
            const int fd = socket(static_cast<int>(family),
                                static_cast<int>(type), 
                                static_cast<int>(protocol));
            // if (fd == -1)
            // {
            //     throw dlagon::exception::Exception("获取套接字描述符失败");
            // }
            return Socket{fd};
        }
        const std::shared_ptr<const int> Socket::PointerFD() const{
            return fd_;
        }
        const int Socket::FD() const{
            return *fd_;
        }
}