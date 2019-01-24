// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.11

/*
   添加Cookie示例,使用cookie来保持登录
   访问localhost:8080/login.html
*/


#include "dlagon.h"
#include "string"

using namespace std;
using namespace dlagon::http;

using namespace dlagon;

HttpResponse login(HttpRequest req){
   HttpResponse res{HttpResponseHeader{HTTP_RESPONSE_PROTOCOL_200},""};
   res.Header().ArgTable().Set("Content-Type","text/html");


   // 登录中用户返回特定的页面
   if (req.Header().Cookies().Get("USER") == "HELLO"){
      res.SetBody("<head><meta charset=\"utf8\"></head><h1>登录中用户</h1>");      
      return res;
   }
   

   //非登录用户返回普通页面,并设置cookie
   res.SetBody("<head><meta charset=\"utf8\"></head><h1>login</h1>");
   res.AddCookie(Cookie("USER","HELLO"));

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