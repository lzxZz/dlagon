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

string cookie_req = 
R"(GET /index.html HTTP/1.1
Host: www.baidu.com
Connection: keep-alive
Cookie: BAIDUID=38C52EB7B5C730C5967E038EEE6744CF:FG=1; BIDUPSID=38C52EB7B5C730C5967E038EEE6744CF; PSTM=1555997005; BD_UPN=13314752; sug=3; sugstore=0; ORIGIN=0; bdime=0; BDORZ=FFFB88E999055A3F8A630C64834BD6D0; H_PS_PSSID=1452_21118_29064_28519_29098_28724_28964_28835_28584_20718; H_PS_645EC=f10apUtxg9KuH7w%2BghtiaiOZfTOv7eNKaNYBAaE3qRGjPNClTnWl7qXfaHrHh3%2Bx%2BIUu; COOKIE_SESSION=32107_0_7_1_10_13_0_3_1_7_103_2_0_0_1_0_1558400483_0_1558432589%7C9%230_1_1557907026%7C1; delPer=0; BD_CK_SAM=1; PSINO=7; BDSVRTM=0
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
   
   


   // EXPECT_EQ(*req, *req);

}


