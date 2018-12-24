/*
*  用于测试相关类中的operator==()运算
* 
*
*/

#include <gtest/gtest.h>

#include "dlagon.h"

using namespace dlagon;
using namespace dlagon::http;

TEST(RequestTest, Equal)
{
   using Head = HttpRequestHeader;
   using M = HttpMethod;
   using Req = HttpRequest;
   Head h{M::GET, "/", "HTTP/1.1"};

   Req lreq{h,""};
   
   EXPECT_EQ(lreq, lreq);
}

TEST(RequestTest, NoEqual)
{
   using Head = HttpRequestHeader;
   using M = HttpMethod;
   using Req = HttpRequest;
   Head h{M::GET, "/", "HTTP/1.1"};

   Req lreq{h,""};
   Req rreq{h,"body"};

   EXPECT_NE(lreq, rreq);
}

TEST(RequestHeaderTest, Equal)
{
   using Head = HttpRequestHeader;
   using M = HttpMethod;
   
   Head h{M::GET, "/", "HTTP/1.1"};
   EXPECT_EQ(h, h);
}

TEST(RequestHeaderTest, NoEqual)
{
   using Head = HttpRequestHeader;
   using M = HttpMethod;
   
   Head lh{M::GET, "/", "HTTP/1.1"};
   Head rh{M::POST, "/", "HTTP/1.1"};
   Head oh{M::GET, "//", "HTTP/1.1"};
   EXPECT_NE(lh, rh);
   EXPECT_NE(lh, oh);
   EXPECT_NE(oh, rh);

}

TEST(PathTest, Equal)
{
   Path p{"/"};
   EXPECT_EQ(p, p);
}

TEST(PathTest, NoEqual)
{
   Path lp{"/"};
   Path rp{"--"};
   EXPECT_NE(lp, rp);
}