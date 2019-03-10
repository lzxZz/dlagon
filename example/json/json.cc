
#include "dlagon.h"
#include <thread>
#include <tuple>

using namespace std;
using namespace dlagon;
using namespace dlagon::http;
using namespace dlagon::net;


void worker(HttpClient client){
   cout << client.Recevie() << endl;

   HttpResponse res{HttpResponseHeader{HTTP_RESPONSE_PROTOCOL_200},
                  "{\"status\":\"OK\"}"};
   
   res.Header().ArgTable().Set("Content-Type","text/json");
   
   client.Send(res.ToString());
}


int main(){
   try{
      HttpServer server;
      server.Bind();
      server.Listen();
      for (;;){
         tuple<HttpClient, EndPoint> result =  server.Accept();
         HttpClient client = std::get<0>(result);

         // 每一个链接过来的客户端使用一个单独的线程进行处理.
         std::thread th{worker, client};
         th.detach();
      }
   }catch(dlagon::exception::Exception &e){
      cout << e.What() << endl;
   }
}