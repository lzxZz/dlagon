#ifndef DLAGON_HTTP_ARG_H_
#define DLAGON_HTTP_ARG_H_

#include <unordered_map>
#include <string>


namespace dlagon 
{
    class Argument
    {
    public:
        Argument(){}
        //使用参数字符串进行构造
        Argument(std::string s);
        //按照指定参数名查找参数,未找到返回空字符串
        std::string find(std::string); 
        //返回所有的参数,每行都是key:value.一个参数占一行
        std::string list();
    private:
        std::unordered_map<std::string, std::string> args;      //hash表存储参数.
    };
}

#endif//DLAGON_HTTP_ARG_H_