#include "dlagon/net/socket.h"

#include <string>

#include "dlagon/error/exception.h"

using std::string;

namespace lzx::dlagon::net{
   void Socket::release_socket(const int* const fd){
        // std::cout << "---------xigou----------\n";    
        int status = close(*fd);
        if (status == -1){
            string info = "Close 套接字描述符失败\n要关闭的描述符为 : ";
            info.append(std::to_string(*fd));
            info.append("\n错误消息为 : ");
            info.append(strerror(errno));
            throw lzx::dlagon::exception::Exception{info};
        }
        
    }

   Socket Socket::New(SocketFamily family, 
                        SocketType type, 
                        SocketProtocolType protocol){
            const int fd = socket(static_cast<int>(family),
                                static_cast<int>(type), 
                                static_cast<int>(protocol));
            if (fd == -1)
            {
                throw lzx::dlagon::exception::Exception(string{strerror(errno)});
            }
            return Socket{fd};
        }
        const std::shared_ptr<const int> Socket::PointerFD() const{
            return fd_;
        }
        const int Socket::FD() const{
            return *fd_;
        }
}