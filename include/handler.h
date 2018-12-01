#ifndef DLAGON_HANDLER_H_
#define DLAGON_HANDLER_H_

#include "path.h"
#include "http/request.h"
#include "http/response.h"

namespace dlagon{
    using HANDLER = dlagon::Http_Response (*)(dlagon::Http_Request);
    
    class Handler{
    public:
        Path path;
        dlagon::HANDLER hand;
        Handler(Path p, HANDLER h) : path(p), hand(h)
        {

        }
    };
    
}

#endif//DLAGON_HANDLER_H_