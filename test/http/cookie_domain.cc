#include <gtest/gtest.h>

#include "http/cookie_domain.h"

using dlagon::http::CookieDomain;

TEST(CookieDomainTest, AddSubDomain)
{
    CookieDomain domain1{"www.example.com"};
    CookieDomain domain2;
    domain2.AddSubDomain("com");
    domain2.AddSubDomain("example");
    domain2.AddSubDomain("www");

    EXPECT_EQ(domain1, domain2);
}

TEST(CookieDomainTest, Tostring)
{
    EXPECT_EQ("www.example.com", CookieDomain{"www.example.com"}.ToString());
}

TEST(CookieDomainTest, Contain)
{
    EXPECT_TRUE(CookieDomain{"com"}.Contain(CookieDomain{"com"}));
    EXPECT_TRUE(CookieDomain{"com"}.Contain(CookieDomain{"example.com"}));
    EXPECT_TRUE(CookieDomain{"com"}.Contain(CookieDomain{"foo.com"}));
    EXPECT_FALSE(CookieDomain{"com"}.Contain(CookieDomain{"org"}));
    EXPECT_FALSE(CookieDomain{"com"}.Contain(CookieDomain{"foo.org"}));
}


TEST(CookieDomainTest, PartOf)
{
    EXPECT_TRUE(CookieDomain{"com"}.PartOf(CookieDomain("com")));
    EXPECT_TRUE(CookieDomain{"foo.com"}.PartOf(CookieDomain("com")));
    EXPECT_TRUE(CookieDomain{".com"}.PartOf(CookieDomain("com")));
}