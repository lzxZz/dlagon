
#include <gtest/gtest.h>

#include "dlagon.h"

using namespace dlagon;
using namespace dlagon::http;

TEST(RequestArgTest, GetArgTest)
{
    using Head = HttpRequestHeader;
    HttpRequest req = HttpRequest::Parse("GET /?a=1&b=2 HTTP/1.1\r\n");
    Head std_head =  Head(HttpMethod::GET, "/", "HTTP/1.1");
    
    EXPECT_EQ("1", req.UrlArgument().Get("a"));
    EXPECT_EQ("2", req.UrlArgument().Get("b"));
    EXPECT_EQ("", req.UrlArgument().Get("c"));
    // EXPECT_EQ(std_req, req);
}
