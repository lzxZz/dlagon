// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.9

/*
   Cookie的测试
*/


#include "dlagon.h"
#include <gtest/gtest.h>

using namespace dlagon::http;

TEST(CookieTest, WkDays){
   EXPECT_STREQ(Cookie::Days(2019,1,9), "Wed");

   EXPECT_STREQ(Cookie::Days(2018,4,9), "Mon");

   EXPECT_STREQ(Cookie::Days(2013,11,9), "Sat");

   EXPECT_STREQ(Cookie::Days(2000,1,9), "Sun");
   
}

TEST(CookieTest, Expires){
   EXPECT_EQ(Cookie("","").SetExpires(2019,1,9).Expires(), "Wed, 09 Jan 2019 00:00:00 GMT");
}