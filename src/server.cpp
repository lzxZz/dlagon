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

using std::ifstream;
using std::string;
using std::vector;
using std::cout;
using std::endl;
// extern "C"
// {
// #include "unp.h"
//     void run(sockaddr_in servaddr, int linstenfd)
//     {

//     }
// }

const string root_dir = "/media/disk/StudyFile/Project/dlagon/static";

void Server::run(int port = 80)
{
    sockaddr_in servaddr;
    
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        cout << "创建服务器套接字失败!" << endl;
        return ;
    }
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if (bind(server_fd, (sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        cout << "绑定服务器套接字失败!" << endl;
        return ;
    }

    if (listen(server_fd, 1024) == -1) 
    {
           cout << "监听服务器套接字失败!" << endl;
           return;
    }

    //::run(servaddr,server_fd);
    for (;;)
    {
        int connfd = accept(server_fd, (sockaddr *)NULL, NULL);
        // Content-Length : 21\r\n
        char hello[] = "HTTP/1.1 200 OK\r\nContent-Type : text/html\r\n\r\n<h1>Hello Wrold!</h1>";

        int n = 0;
        char *buf = new char[1024];

        string input;

        string str{};

        do
        {
            n = read(connfd, buf, 1024);
            // std::cout << n << "\t" <<buf <<  std::endl;
            str.append(buf,n);
        } while (n == 1024);
        delete[] buf;
        
        dlagon::Http_request request = dlagon::parse_to_request(str);

        cout << request.method_str << "\t" << request.path << "\t" << request.version << endl;
        
        //空对象请求,
        if (request.path == "")
        {
            cout << "请求了一个空对象" << endl;
            close(connfd);
            continue;
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


            string err = "HTTP/1.1 404 Not Found\r\n"
                         "Content-Type : text/html\r\n"
                         "\r\n";

            ifstream input;
            input.open("./static/404.html");
            string buf;
            while (getline(input, buf))
            {
                err.append(buf);
                err.append("\n");
            }
            

            write(connfd, err.c_str(), err.size());
            // cout << "404已返回" << "\n" << err << endl;
            input.close();
            close(connfd);
        }
        else
        {
                cout << "请求对象" << request.path << "存在" << endl;
                string info = "HTTP/1.1 200 OK\r\n"
                              "Content-Type : text/html\r\n"
                              "\r\n";
                
                ifstream input;
                input.open(root_dir + request.path);
                string buf;
                while (getline(input, buf))
                {
                    info.append(buf);
                    info.append("\n");
                }
                
                write(connfd, info.c_str(), info.size());
                input.close();
                close(connfd);

        }



        // write(connfd, hello, strlen(hello));

        // 关闭连接
        
    }
}
