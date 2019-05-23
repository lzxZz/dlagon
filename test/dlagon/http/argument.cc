#include <gtest/gtest.h>

#include "dlagon/http/argument.h"

using namespace lzx::dlagon::http;
using std::string;



HttpArgumentFactory factory;


TEST(HttpArgumentTest, EmptyStringTest){
   
   HttpArgument *arg =  dynamic_cast<HttpArgument*>(factory.FromString(""));

   EXPECT_EQ(HttpArgument{} ,*arg);
}

TEST(HttpArgumentTest, SetTest){

}



TEST(HttpArgumentTest, CookieTest){
   // HttpArgument *req = dynamic_cast<HttpArgument*>(factory.FromString(cookie_req));
}