/* 文档转换类，讲一个lmd语法的文档转化为html
*
*
*创建于2018-08-26    write by lzx
*/
#include "term.h"
#include <string>
using std::string;
class Parser{

public:
    //输入参数,css,字符编码,要转换的内容
    // css多个文件使用逗号分隔
    string parse(string css,string ch,string content);
};