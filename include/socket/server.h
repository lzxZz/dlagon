#ifndef DLAGON_SOCKET_SERVER_H_
#define DLAGON_SOCKET_SERVER_H_

#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "excption.h"

namespace dlagon
{
    class Server_Socket{
         public:
        Server_Socket(int port = 8080) : server_fd(-1)
        {
            //获取不为-1的服务端套接字的描述符.
            while (server_fd == -1)
            {
                server_fd = socket(AF_INET, SOCK_STREAM, 0);
            }

            //sockaddr_in server_address;
            bzero(&server_address, sizeof(server_address)); //初始化服务地址

            server_address.sin_family = AF_INET;
            server_address.sin_addr.s_addr = htonl(INADDR_ANY);
            server_address.sin_port = htons(port);

        }

        Server_Socket &bind()
        {   
            //用::调用全局作用域,防止无限递归
            if (::bind(server_fd, (sockaddr *) &server_address, sizeof(server_address)) == -1)
            {
                throw Failed_bind_excption("failed in call server_socket::bind");
            }
            return *this;   
        }
        Server_Socket &bind(sockaddr_in servaddr)
        {
            if (::bind(server_fd, (sockaddr *) &servaddr, sizeof(servaddr)) == -1)
            {
                throw Failed_bind_excption("failed in call server_socket::bind");
            }
            return *this;
        }
        
        //默认监听队列大小为1024
        Server_Socket &listen(size_t queue_length = 1024)
        {
            if (::listen(server_fd, queue_length) == -1) 
            {
                throw Failed_listen_excption("failed in call server_socket::listen");
            }
            return *this;
        }

        uint32_t fd()
        {
            return this->server_fd;
        }

    private:
        int                             server_fd;          //socket对应的套接字
        // int                             port;               //绑定的端口
        sockaddr_in                     server_address;     //服务地址,包含端口号

    };
}
#endif //DLAGON_SOCKET_SERVER_H_