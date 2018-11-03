#include "../include/server.h"
#include <sys/socket.h>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include <boost/algorithm/string.hpp>

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

void Server::run(int port = 80)
{
    sockaddr_in servaddr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    bind(server_fd, (sockaddr *)&servaddr, sizeof(servaddr));

    listen(server_fd, 1024);

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
        // std::cout << "返回结果" << std::endl;

        write(connfd, hello, strlen(hello));

        // 关闭连接
        close(connfd);
    }
}
