#include <gtest/gtest.h>


#include "dlagon/common/result.h"
#include <string>

using std::string;

using lzx::dlagon::Result;
using lzx::dlagon::ResultType;

TEST(ResultTypeTest, OkTest){
    Result<int> result = Result<int>::NewOk(10);
    EXPECT_EQ(ResultType::Ok, result.Valid());
    EXPECT_EQ(10, result.Value());
    
}

TEST(ResultTypeTest, ErrTest){
    Result<string> result = Result<string>::NewErr("");
    EXPECT_EQ(ResultType::Err, result.Valid());
    EXPECT_EQ("", result.Value());
    
}