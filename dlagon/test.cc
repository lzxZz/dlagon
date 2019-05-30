/**
 * @file test.cc
 * @author lzxZz (616281384@qq.com)
 * @brief 用于运行临时代码
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "dlagon/http/response.h"
#include <iostream>



using namespace lzx::dlagon::http;
using namespace std;

int main(){
    HttpResponse res{200, 
    dynamic_cast<HttpArgument*>(HttpArgumentFactory::GetInstant()->FromString("Content-Type : text/html")), 
    "content"};

    cout << res.ToString() << endl;

    cout << HttpResponse::HTTP_HTML_200.ToString() << endl;
    cout << HttpResponse::HTTP_HTML_404.ToString() << endl;
}