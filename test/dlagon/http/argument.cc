#include <gtest/gtest.h>

#include "dlagon/http/argument.h"

using namespace lzx::dlagon::http;

TEST(HttpArgumentTest, EmptyString){
   HttpArgumentFactory factory;
   HttpArgument *arg =  dynamic_cast<HttpArgument*>(factory.FromString(""));

   EXPECT_EQ(HttpArgument{} ,*arg);
}

TEST(HttpArgumentTest, Set){

}