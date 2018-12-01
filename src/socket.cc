#include "socket/socket.h"

#include <string>

using std::string;
using std::to_string;

dlagon::Socket &dlagon::Socket::operator<<(const string &info)
{
    ::write(this->fd(), info.c_str(), info.size());

    return *this;
}



dlagon::Socket &dlagon::Socket::operator<<(const int info)
{
    *this << to_string(info);
    return *this;
}

dlagon::Socket &dlagon::Socket::operator<<(const dlagon::Http_Response &response)
{
    *this << response.version << " " << response.state << " " << response.state_info << "\r\n";

    for (auto p : response.header)
    {
       *this << p.first << ":" << p.second << "\r\n";
    }
    *this << "\r\n";

    *this << response.body;

    return *this;
}
