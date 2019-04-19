// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.24

/*
   单元测试启动函数
*/


#include <gtest/gtest.h>

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    cout << __func__ << __FILE__ << __LINE__ << endl;
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}