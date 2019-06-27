#ifndef LZX_DLAGON_HTTP_MIDWARE_ROUTE_BASIC_ROUTE_H_
#define LZX_DLAGON_HTTP_MIDWARE_ROUTE_BASIC_ROUTE_H_

#include <string>
#include <map>

#include "dlagon/http/midware/route/handler.h"
#include "dlagon/interface/midware.h"
#include "dlagon/interface/protocol/request.h"
#include "dlagon/interface/protocol/response.h"

namespace lzx::dlagon::http::midware{

/**
 * @brief 基本的路由中间件, 使用全匹配
 * 
 */
class BasicRoute  : public lzx::dlagon::interface::Midware{
public:
    BasicRoute(const Handler *no_match)
        : not_match_hanlder_(no_match) {}
    BasicRoute(){}
    
    const Handler *Distribute(const std::string &path) const;
    BasicRoute &Regiest(const std::string &path, const Handler hanlder);
    lzx::dlagon::interface::Midware::MidwareState Handle(const lzx::dlagon::interface::Request &req, lzx::dlagon::interface::Response &res) override;
private:
    std::map<std::string, Handler> handlers_;
    const Handler *not_match_hanlder_ = nullptr;
};

}



#endif //LZX_DLAGON_HTTP_MIDWARE_ROUTE_BASIC_ROUTE_H_