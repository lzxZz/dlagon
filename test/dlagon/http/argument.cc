#include <gtest/gtest.h>

#include "dlagon/http/argument.h"

using namespace lzx::dlagon::http;
using std::string;

using lzx::dlagon::Result;
using lzx::dlagon::ResultType;


HttpArgumentFactory factory;


TEST(HttpArgumentTest, EmptyStringTest){
   
   HttpArgument *arg =  dynamic_cast<HttpArgument*>(factory.FromString(""));

   EXPECT_EQ(HttpArgument{} ,*arg);
}

TEST(HttpArgumentTest, SetTest){
   HttpArgument arg1, arg2;
   arg1.Set("1","2");
   arg2.Set("1","2");

   EXPECT_EQ(arg1, arg2);
}


TEST(HttpArgumentTest, GetTest){
   HttpArgument arg1, arg2;
   arg1.Set("key","value");
   

   auto result = arg1.Get("key");
   EXPECT_EQ(ResultType::Ok, result.Valid());
   EXPECT_EQ("value", result.Value());

   result = arg1.Get("key1");
   EXPECT_EQ(ResultType::Err, result.Valid());
   EXPECT_EQ("不存在的参数名", result.Value());
}

