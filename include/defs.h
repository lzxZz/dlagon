#ifndef __DEFS_H
#define __DEFS_H


#include <unordered_map>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <exception>
#include <cstring>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include <cassert>

#include <iostream>
namespace dlagon{
    enum class Http_method{
        GET,
        POST,
        HEAD,
        PUT,
        DELETE,
        TRACE,
        CONNENCTION,
        OTHER
        
    };
    enum class Mime_type{

    };
    class Failed_bind_excption {
    public:
        Failed_bind_excption(std::string m = "") : msg(m)
        {
        }
        ~Failed_bind_excption() = default;                              //默认析构
        Failed_bind_excption(Failed_bind_excption&) = default;          //默认拷贝构造
        Failed_bind_excption(Failed_bind_excption&&) = default;         //默认移动构造
        std::string const &message() const
        {
            return this->msg;
        }
    private:    
        std::string                          msg;                //异常消息

    };

    class Failed_read_excption {
    public:
        Failed_read_excption(std::string m = "") : msg(m)
        {
        }
        ~Failed_read_excption() = default;                              //默认析构
        Failed_read_excption(Failed_read_excption&) = default;          //默认拷贝构造
        Failed_read_excption(Failed_read_excption&&) = default;         //默认移动构造
        std::string const &message() const
        {
            return this->msg;
        }
    private:    
        std::string                          msg;                //异常消息

    };

    class Failed_listen_excption {
    public:
        Failed_listen_excption(std::string m = "") : msg(m)
        {
        }
        ~Failed_listen_excption() = default;                              //默认析构
        Failed_listen_excption(Failed_listen_excption&) = default;          //默认拷贝构造
        Failed_listen_excption(Failed_listen_excption&&) = default;         //默认移动构造
        std::string const &message() const
        {
            return this->msg;
        }
    private:    
        std::string                          msg;                //异常消息

    };
    
    class Http_request{
    public:
        std::unordered_map<std::string, std::string>        header;         //请求头的键值对
        std::string                                         body;           //请求数据体
        Http_method                                         method;         //请求的方法
        std::string                                         method_str;     //请求方法的字符串表示
        std::string                                         path;           //请求的路径
        std::string                                         version;        //请求的协议版本
    };

    class Http_response{
    public:
        Http_response(std::string v, int code, std::string s) : version(v), state(code), state_info(s)
        {
            
        }
        std::string                                         version;        //协议版本
        int                                                 state;          //状态码
        std::string                                         state_info;     //状态码对应的字段
        std::unordered_map<std::string, std::string>        header;         //响应头
        std::string                                         body;           //响应体
        void set_body(std::string path)
        {
            std::ifstream input(path);
            if (input.is_open())
            {
                string line;
                while (getline(input, line))
                {
                    body.append(line);
                    body.append("\n");
                }

            }
            else
            {

                input.close();
                throw Failed_read_excption("read error");
            }
            
            input.close();
        }
    };
    Http_request parse_to_request(const std::string&);

    ///http方法枚举类型
    
    class Server_socket{
    public:
        Server_socket(int port = 8080) : server_fd(-1)
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

        Server_socket &bind()
        {   
            //用::调用全局作用域,防止无限递归
            if (::bind(server_fd, (sockaddr *) &server_address, sizeof(server_address)) == -1)
            {
                throw Failed_bind_excption("failed in call server_socket::bind");
            }
            return *this;   
        }
        Server_socket &bind(sockaddr_in servaddr)
        {
            if (::bind(server_fd, (sockaddr *) &servaddr, sizeof(servaddr)) == -1)
            {
                throw Failed_bind_excption("failed in call server_socket::bind");
            }
            return *this;
        }
        
        //默认监听队列大小为1024
        Server_socket &listen(size_t queue_length = 1024)
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
    

    class Socket {
    public:
        Socket (int n) : socket_fd(n)
        {

        }
        Socket(Socket&) = default;
        Socket(Socket&&) = default;
        ~Socket()
        {
            ::close(socket_fd);
            std::cout << "~Socket:" << fd() << std::endl;
        }


        // std::ostringstream              out;            //写入对象
        // std::istringstream              in;             //读取对象

        // const std::ostringstream &operator<<(const std::ostringstream &os, const std::string info)
        // {

        // }
        Socket &operator<<(const std::string &info)
        {
            ::write(socket_fd, info.c_str(), info.size());
            return *this;
        }

        Socket &operator<<(const int info)
        {
            *this << std::to_string(info);
            return *this;
        }

        Socket &operator<<(const Http_response &response)
        {
            *this  << response.version << " " << response.state << " " << response.state_info << "\r\n";

            

            for (auto p : response.header)
            {
                *this <<  p.first << ":" << p.second << "\r\n";
            }
            *this << "\r\n";

            *this << response.body;


            return *this;
        }

        Http_request get_req()
        {
            const int BUFSZIE = 1024;

            int n;
            char *buf =new char[BUFSZIE];
            std::string info;
            do 
            {
                n = read(fd(), buf, BUFSZIE);
                if (n == -1)
                {
                    throw Failed_read_excption("error on read from socket!");
                }
                info.append(buf,n);
            }while (n == BUFSZIE);

            delete[] buf;
            return parse_to_request(info);
        }

        const int fd(){
            return socket_fd;
        }
    private:
        int                             socket_fd;             //关联的文件描述符
    };
    
}

#endif