#include "dlagon/web/server.h"

using namespace lzx::dlagon::web;

int main(){
   WebServer server;

   server.Run(8080);
}