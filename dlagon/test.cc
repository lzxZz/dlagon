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

#include "dlagon/web/id_pool.h"

using namespace lzx::dlagon::http;
using namespace std;

using namespace lzx::dlagon::web;

int main(){
    // HttpResponse res{200, 
    // dynamic_cast<HttpArgument*>(HttpArgumentFactory::GetInstant()->FromString("Content-Type : text/html")), 
    // "content"};

    // cout << res.ToString() << endl;

    // cout << HttpResponse::HTTP_HTML_200.ToString() << endl;
    // cout << HttpResponse::HTTP_HTML_404.ToString() << endl;

    IdPool pool{5};
    cout << pool.Capcity() << endl;
    pool.ExpendPool(20);
    pool.ExpendPool(10);
    // string id = pool.ApplyId();
    for (auto i =0 ; i < 1000; i++){
        cout << i << "\t" << pool.ApplyId() << "\t" << pool.Capcity() << endl;
    }
}