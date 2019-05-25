/**
 * @file request.cc
 * @author lzxZz (616281384@qq.com)
 * @brief HTTP请求解析
 * @version 0.1
 * @date 2019-05-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <gtest/gtest.h>

#include <string>
#include "dlagon/http/request.h"
#include "dlagon/http/protocol_factory.h"

using namespace std;
using namespace lzx::dlagon::http;

#include <iostream>
using namespace std;

string basic_http_request1 = 
R"(GET /index.html HTTP/1.1
Host:www.baidu.com
Connnection: keep-alive
)";

string basic_http_request2 = 
R"(POST /index.html HTTP/1.1
Host:www.baidu.com
Connnection: keep-alive
)";

string cookie_req = 
R"(GET /index.html HTTP/1.1
Host: www.baidu.com
Connection: keep-alive
Cookie: key=value; key1=value1
Upgrade-Insecure-Requests: 1
)";

TEST(HttpRequestTest, ParserTest){
   HttpRequest *req = dynamic_cast<HttpRequest*>(HttpProtocolFactory::GetInstant()->RequestFromString(basic_http_request1));
   
   
   HttpRequest *req2 = dynamic_cast<HttpRequest*>(HttpProtocolFactory::GetInstant()->RequestFromString(basic_http_request2));

   HttpRequest *basic_req = dynamic_cast<HttpRequest*>(HttpProtocolFactory::GetInstant()->RequestFromString(basic_http_request1));
   

   EXPECT_EQ(*req, *req);
   EXPECT_EQ(*basic_req, *req);
   
   EXPECT_NE(*basic_req, *req2);
}


TEST(HttpRequestTest, ParserCookieTest){
   HttpRequest *req = dynamic_cast<HttpRequest*>
                     (HttpProtocolFactory
                        ::GetInstant()
                        ->RequestFromString(cookie_req));
   
   HttpArgument arg;
   arg.Set("key","value");
   arg.Set("key1","value1");


   
   EXPECT_EQ(req->GetCookies(), arg);

}


