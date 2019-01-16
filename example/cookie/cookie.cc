// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.9

/*
   带有Cookie的Http的基本示例
*/

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
                  "<h1>Test Page</h1>"};
   
   res.Header().ArgTable().Set("Content-Type","text/html");

   //增加了Cookie
   res.AddCookie(Cookie{"STR","HELLO-COOKIE"}.SetMaxAge(10));  
   //设置了10秒的最大寿命没有作用,照样会从浏览器返回到服务端
   
   string str = res.ToString();

   cout << "响应字符串:\n" << str << endl;

   client.Send(res);
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