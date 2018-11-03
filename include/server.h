#ifndef __SERVER_H
#define __SERVER_H

#include "defs.h"

class Server{
    
    int server_fd;
    int port;
    
public:
    void run(int port);
    ~Server() = default;
    Server() = default;
    Server(int port): port(port){

    }
};


#endif
