#ifndef LZX_DLAGON_HTTP_MIDWARE_HANDLER_H_
#define LZX_DLAGON_HTTP_MIDWARE_HANDLER_H_

#include "dlagon/http/request.h"
#include "dlagon/http/response.h"

namespace lzx::dlagon::http::midware{

class Handler{
using HandleFunction = void(*)(const HttpRequest &req, HttpResponse &res);
public:
    Handler(HandleFunction f) : func_(f) {}
    void operator()(const lzx::dlagon::interface::Request &req, lzx::dlagon::interface::Response &res){
        func_(dynamic_cast<const HttpRequest&>(req), dynamic_cast<HttpResponse&>(res));
    }
private:
    HandleFunction func_;
};

}


#endif //LZX_DLAGON_HTTP_MIDWARE_HANDLER_H_