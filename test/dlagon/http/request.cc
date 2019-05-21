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

TEST(HttpRequestTest, test){
   HttpRequest *req = dynamic_cast<HttpRequest*>(HttpProtocolFactory::GetInstant()->RequestFromString(basic_http_request1));
   
   
   HttpRequest *req2 = dynamic_cast<HttpRequest*>(HttpProtocolFactory::GetInstant()->RequestFromString(basic_http_request2));

   HttpRequest *basic_req = dynamic_cast<HttpRequest*>(HttpProtocolFactory::GetInstant()->RequestFromString(basic_http_request1));
   

   EXPECT_EQ(*req, *req);
   EXPECT_EQ(*basic_req, *req);
   
   EXPECT_NE(*basic_req, *req2);
}