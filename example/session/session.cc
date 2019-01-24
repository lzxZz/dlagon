#include "dlagon.h"

#include <iostream>
using namespace std;
using namespace dlagon;
using namespace dlagon::http;


HttpResponse login(HttpRequest req, Session session){
   HttpResponse res{HttpResponseHeader{HTTP_RESPONSE_PROTOCOL_200},""};
   res.Header().ArgTable().Set("Content-Type","text/html");
    
   string info = "<head><meta charset=\"utf8\"></head><h1>Session Test</h1>\n";
   
   info.append("<div>当前会话访问次数为:" + std::to_string(session.Historical().size()));
   info.append("</div>");

   res.SetBody(info);
   cout << session.ID() << endl;

   return res;
}



int main(){
    
   try
   {
      cout << "启动" << endl;

      //运行示例时,请手动填充下面的变量
      string root_dir = "/";
      Server server;
      Route route{};
      
      //使用route.Register()来给指定的path注册对应的处理方法
      //注册路径时必须带上前缀斜杠
      route.Register(Path{"/login.html"}, Handler{login});
      
      server.SetRoute(route);
      server.Run(root_dir, 8080);
      
   }
   catch(const dlagon::exception::Exception& e)
   {
      std::cerr << e.What() << '\n';
   }
   return 0;
}