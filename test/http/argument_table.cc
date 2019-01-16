#include "dlagon.h"
#include <gtest/gtest.h>

using dlagon::ArgumentTable;
TEST(ArgTest, ToString){
    
    EXPECT_EQ("k:v\r\n", ArgumentTable{}.Set("k","v").ToString());

    EXPECT_EQ("k:v\r\nkkk:vvv\r\n", ArgumentTable{}.Set("k","v").Set("kkk","vvv").ToString());

        EXPECT_EQ("k:v\r\n", ArgumentTable{}.Set("k","v").Set("kkk","vvv").Remove("kkk").ToString());




}