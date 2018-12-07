#ifndef DLAGON_SERVER_H_
#define DLAGON_SERVER_H_

#include <regex>
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
  std::vector<std::string> allow_list;

public:
  void run(int port = 8080);
  void run();

  ~Server() = default;
  Server() = default;
  Server(std::string rd, int p = 8080) : root_dir(rd), port(p)
  {
  }
  const std::string root()
  {
    return root_dir;
  }
  //根据路径,搜索指定的处理程序.
  const HANDLER find_handler(Path path);
  //添加对应的访问和指定的处理程序
  Server &add_path(dlagon::Path, dlagon::HANDLER);
  //添加允许访问的位置.
  Server &allow_path(std::string);
  bool allow(std::string path)
  {
    using std::regex;
    using std::regex_match;
    for (auto p : allow_list)
    {
      regex reg(p);
      if (regex_match(path, reg))
      {
        return true;
      }
    }

    return false;
  }
};
} // namespace dlagon

#endif //DLAGON_SERVER_H_