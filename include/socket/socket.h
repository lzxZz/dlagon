#ifndef DLOGON_SOCKET_H_
#define DLOGON_SOCKET_H_

#include <unistd.h>

#include <string>

#include "http/response.h"
#include "http/request.h"
#include "excption.h"

using dlagon::Http_Request;
using dlagon::Http_Response;

namespace dlagon
{
class Socket
{
    int socket_fd;

  public:
    Socket(int fd) : socket_fd(fd) {}
    Socket(Socket &) = default;
    Socket(Socket &&) = default;
    ~Socket()
    {
        ::close(socket_fd);
    }

    Http_Request request()
    {
        int n;
        char *buf = new char[BUFSIZ];
        std::string info;
        do
        {
            n = read(fd(), buf, BUFSIZ);
            if (n == -1)
            {
                throw Failed_read_excption("error on read from socket!");
            }
            info.append(buf, n);
        } while (n == BUFSIZ);
        delete[] buf;
        return parse_to_request(info);
    }

    const int fd()
    {
        return socket_fd;
    }

    dlagon::Socket &operator<<(const std::string &info);
    dlagon::Socket &operator<<(const int info);
    dlagon::Socket &operator<<(const dlagon::Http_Response &response);
};

} // namespace dlagon

#endif // DLOGON_SOCKET_H_