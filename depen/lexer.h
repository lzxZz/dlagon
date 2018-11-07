#ifndef __LEXER_H
#define __LEXER_H

#include <vector>
#include <string>
using std::string;
using std::vector;

enum class ToKen_Type
{
    TITLE,      //标题
    TEXT,       //正常文本
    ORDER,      //序号数字      "\n\S*\d+\. "
    LIST,       //有序列表
    BLOD,       //加粗
    ITALY,      //斜体
    SPLIt,      //分割线
    BR,         //换行
    INDENT,     //缩进
    MATH_INNER, //数学公式,行内
    MATH_BLOCK, //数学公式,块
    LATEX,      //LAETX格式新增语法
    QUOT,       //引用
    CODE_INNER, //代码,行内
    CODE_BLOCK, //代码,块
    SYMBLO,     //其他的符号,![](){}
    NONE,        //未知
    SPACE       //空格
};

class Token
{

  public:
    string unit;     //词素数据
    ToKen_Type type; //词素类型
    Token()
    {
        unit = "";
        type = ToKen_Type::NONE;
    }
    Token(string content, ToKen_Type _type) : unit(content), type(_type)
    {
    }
    
    
  
};
bool operator==(const Token &ltoken, const Token &rtoken);

//将输入的字符串转换为词法单元集合.
vector<Token> lexer(string);

#endif
