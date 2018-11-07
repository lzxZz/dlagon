#ifndef __TERM

#define __TERM


#include <string>
using std::string;

#include <sstream>

#ifndef __REGEX
#define __REGEX
#include <regex>
using std::regex;
enum ContinueType{
  CODE,         //代码块
  TABLE,        //表格
  LIST,         //无序列表
  ORDER,        //有序列表
  QUOT,         //引用
  NOTHING       //没有续行
};

static regex indent_reg("    .+?");
static regex tab_reg("\\t.+?");

//段落级别正则
//无续行元素
static regex title_reg("\\#{1,6} .+?");
static regex split_reg("[\\*\\+\\_\\-]{3,}");
static regex math_reg("\\$\\$.+?\\$\\$");
static regex image_reg("!\\[.*?\\]\\(.+?\\)");

//续行元素,空行结束
static regex list_reg("[\\*\\+] .+?");
static regex order_reg("\\d+?\\. .+?");
static regex quot_reg("> .+?");

//空行匹配
static regex space_line_reg("\\s*?");

//续行元素，有结尾标志
static regex code_reg_start("```.*?");
static regex code_reg_end("```");


//\\btab\{c(,c)*?\}\{.*?\}
static regex table_reg_start("\\\\table\\{.*?\\}");
static regex table_reg_end("\\\\table");



//行内元素正则
static regex bold_reg("[\\*\\+]{2}.+?[\\*\\+]{2}");
static regex italy_reg("[\\*\\-\\+].+?[\\*\\-\\+]");
static regex link_reg("\\[.+?\\]\\(.+?\\)");
static regex cls_reg("\\\\cls\\{.+?\\}\\{.+?\\}");
static regex label_reg("\\\\label\\{.+?\\}");
static regex icode_reg("`.+?`");
static regex imath_reg("\\$.+?\\$");


#endif

//所有标签的父类，声明了公有成员和方法
class Term
{

  protected:
    //保存标签带格式文本
    string content;

  public:
    void setContent(string str) {
      content = str;
    }
    virtual string parse()  = 0;
    virtual ~Term(){}
};

//文档类，每一个lmd文档对应一个类
class Document 
:public  Term
{
  public:
    string parse();
    Document() = default;
    Document(string content){
      this->content = content;
    }
};

//所有段落级别的抽象父类
class Section :public  Term
{
protected:
  //bool isParse = false;
  public:
   virtual string parse() = 0;
   Section() = default;
   Section(string content){
     this->content = content;
   }
  ~Section(){}
};

//所有内部元素的抽象父类
class Inner :public  Term
{  
  public:
    string parse();
  ~Inner(){}
};

//标题，对应h1-h6标签
class Title :public  Section
{
  public:    
    string parse();
    Title() = default;
    Title(string content){
      this->content = content;
    }
};
//无序列表
class List :public  Section
{
  public:    
    string parse();
    List() = default;
    List(string content){
      this->content = content;
    }
};
//有序列表
class Order :public  Section
{  
  public:    
    string parse();
    Order()  = default;
    Order(string content){
      this->content = content;
    }
};

//引用

class Quot :public  Section
{  
  public:    
    string parse();
    Quot() = default;
    Quot(string content){
      this->content = content;
    }
};
//直接替换为对应的html
// //分割线
// class Split //:public  Section
// {  
//   public:
//     string parse();
    
// };

// 图片
class Image :public  Section
{ 
  public:
    string parse();
    Image() =default;
    Image(string content){
      this->content = content;
    }
};

// 代码
class Code :public  Section
{
public:
  string parse();
  Code() =default;
  Code(string content){
    this->content = content;

  }
};
// 表格
class Table :public  Section
{
public:
  string parse();
  Table() = default;
  Table(string content){
    this->content = content;
  }
};
// 数学公式
class Math :public  Section
{
public:
  string parse();
  Math() = default;
  Math(string content){
    this->content = content;
  }
};
// 普通文本
class Text :public  Section
{
public:
  string parse();
  Text() = default;
  Text(string content){
    this->content = content;
  }
};

/*
无效的类声明，等待使用语法树时使用。
//指定类名
class ClassTerm :public  Inner
{
public:
      string parse();
};

class Link :public  Inner
{
  public:
       string parse();
};

class Bold :public  Inner
{
  public:
       string parse();
};

class Italy :public  Inner
{
  public:
       string parse();
};

class InnerMath :public  Inner
{
  public:
       string parse();
};

class InnerCode :public  Inner
{
  public:
       string parse();
};

class Label :public  Inner
{
  public:
       string parse();
};

class PlainText :public  Inner
{
  public:
       string parse();
};
*/

#endif
