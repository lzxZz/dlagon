#ifndef DLAGON_CLIENT_H_
#define DLAGON_CLIENT_H_

#include "http/request.h"
#include "http/response.h"

namespace dlagon
{
    class Client{

    public:
        Http_Request request();
        Http_Response response();
    };
}


#endif//DLAGON_CLIENT_H_