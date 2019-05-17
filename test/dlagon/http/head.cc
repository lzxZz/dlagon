#include <gtest/gtest.h>

#include "dlagon/http/head.h"

using namespace lzx::dlagon::http;
using std::string;

class HttpRequestHeadTest : public testing::Test{
public:
   HttpRequestHeadTest(){
      basic_request = new HttpRequestHead("GET","/","HTTP/1.1");
   }
   void SetUp() override{
      factory = HttpHeadFactory::GetInstant();
      
   }

   void TearDown() override{
      delete factory;
   }
// private:
   HttpHeadFactory *factory = nullptr;
   HttpRequestHead *basic_request = nullptr;
};

TEST_F(HttpRequestHeadTest, Builer){
   HttpRequestHead *req =  factory->GetHttpRequestHead("GET / HTTP/1.1");
   EXPECT_EQ(*basic_request, *req);
}