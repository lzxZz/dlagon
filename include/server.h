#ifndef DLAGON_SERVER_H_
#define DLAGON_SERVER_H_

#include <vector>

#include "path.h"
#include "http/request.h"
#include "http/response.h"
#include "handler.h"

namespace dlagon
{


class Server
{

    std::string root_dir;
    int server_fd;
    int port;
    std::vector<dlagon::Handler> hand;
    
  public:
    void run(int port =8080);
    
    ~Server() = default;
    Server() = default;
    Server(std::string rd,int p=8080) : root_dir(rd),port(p)
    {
        
    }
    const std::string root()
    {
      return root_dir;
    }
    const HANDLER find_handler(Path path);
    Server &add_path(dlagon::Path, dlagon::HANDLER);
};
} // namespace dlagon

#endif//DLAGON_SERVER_H_