#include "dlagon/http/midware/route/basic_route.h"

#include <string>

#include "dlagon/http/request.h"
#include "dlagon/interface/protocol/request.h"
#include "dlagon/interface/protocol/response.h"

using std::string;

using lzx::dlagon::http::HttpRequest;
using lzx::dlagon::interface::Midware;
using lzx::dlagon::interface::Request;
using lzx::dlagon::interface::Response;

#include <iostream>
using std::cout;
using std::endl;

namespace lzx::dlagon::http::midware{

const Handler *BasicRoute::Distribute(const string &path) const{
    for (auto it : handlers_){
        if (it.first == path){
            return new Handler(it.second);
        }
    }
    return not_match_hanlder_;    
}

Midware::MidwareState BasicRoute::Handle(const Request &req, Response &res){
    const HttpRequest &request = dynamic_cast<const HttpRequest&>(req);
    const Handler *hanlder = Distribute(request.Head().Uri());
    if (hanlder != nullptr){
        Handler h = *hanlder;
        h(request, res);
    }else{
        cout << "not match" << endl;
        return Midware::MidwareState::kContinue;
    }
    return Midware::MidwareState::kStop;
}

BasicRoute &BasicRoute::Regiest(const std::string &path, const Handler hanlder){
    handlers_.emplace(std::make_pair(path, hanlder));
    return *this;
}

}