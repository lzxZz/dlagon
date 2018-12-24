// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.24




/**
 * 
 *  测试HTTP请求的转换
 *
**/

#include <gtest/gtest.h>

#include "dlagon.h"

using namespace dlagon;
using namespace dlagon::http;

TEST(RequestTest, GetTest)
{
    using Head = HttpRequestHeader;
    HttpRequest req = HttpRequest::Parse("GET / HTTP/1.1\r\n");
    Head std_head =  Head(HttpMethod::GET, "/", "HTTP/1.1");
    HttpRequest std_req =  HttpRequest(std_head,"");
    EXPECT_EQ(std_req, req);
}

TEST(RequestTest, PostTest)
{
    using Head = HttpRequestHeader;
    HttpRequest req = HttpRequest::Parse("Post / HTTP/1.1\r\n\r\nbody");
    Head std_head =  Head(HttpMethod::POST, "/", "HTTP/1.1");
    HttpRequest std_req =  HttpRequest(std_head,"body\n");
    EXPECT_EQ(std_req, req);
}