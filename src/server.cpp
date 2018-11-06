#include "../include/server.h"
#include <sys/socket.h>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

#include <boost/algorithm/string.hpp>



#include <thread>
using std::thread;

using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

const string root_dir = "/media/disk/StudyFile/Project/dlagon/static";

void rw_socket(int fd)
{   
        if (fd == -1)
        {
            return;
        }
        // cout << fd << endl;
        dlagon::Socket socket(fd);
        cout << "link fd : " << socket.fd() << endl;

        
        dlagon::Http_request request;
        try
        {
            request = socket.get_req();
        }
        catch(dlagon::Failed_read_excption e)
        {
            std::cout << e.message() << std::endl;
            return ;
        }
        cout << request.method_str << "\t" << request.path << "\t" << request.version << endl;

        
        
        //空对象请求,
        if (request.path == "")
        {
            cout << "请求了一个空对象" << endl;
            return ;
        }

        //处理请求对象,如果以/结尾,自动转换为/index.html
        if (*request.path.crbegin() == '/'){
            request.path += "index.html";
        }
        
        // access函数判断文件全新,
        //      R_OK,W_OK,X_OK,分别为读,写,执行的权限
        //      F_OK为文件是否存在,
        //成功返回0,出错返回-1
        if (access( (root_dir+request.path).c_str(), F_OK) == -1)
        {
            //对象不存在,返回错误
            cout << "请求对象" << request.path << "不存在" << endl;
            
            dlagon::Http_response response("HTTP/1.1", 404, "Not Found");
            response.header.emplace(std::make_pair("Content-Type","text/html"));
            
            try
            {
                response.set_body("./static/404.html");
            }
            catch(dlagon::Failed_read_excption e)
            {
                std::cout << e.message << '\n';
            }
            
            socket << response ;
            
        }
        else
        {
                cout << "请求对象" << request.path << "存在" << endl;

                dlagon::Http_response response("HTTP/1.1", 200, "OK");
                response.header.emplace(std::make_pair("Content-Type","text/html"));
                
                try
                {
                    response.set_body(root_dir + request.path);
                }
                catch(dlagon::Failed_read_excption e)
                {
                    std::cout << e.message << '\n';
                }
            
                socket << response ;
                
        }
    
}


void Server::run(int port = 8080)
{
    dlagon::Server_socket server{8080}; //使用8080端口初始化服务套接字地址

    try
    {
        server
            .bind()         
            .listen();
    }
    catch(dlagon::Failed_bind_excption e)
    {
        cout << e.message() << endl;
    }
    catch(dlagon::Failed_bind_excption e)
    {
        cout << e.message() << endl;
    }

    cout << "run server on localhost:8080" << endl;

    //::run(servaddr,server_fd);
    for (;;)
    {
        int client_fd = accept(server.fd(), (sockaddr *)NULL, NULL);

        //开启新线程
        thread client_thread(rw_socket, client_fd);
        // if (client_thread.joinable())
        //     client_thread.join();           //不加join会直接崩溃,原因未知
        client_thread.detach();                 //将线程分离开来,独立运行
    }
}
