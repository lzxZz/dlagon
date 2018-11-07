/*
读写文件操作
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::fstream;
using std::ifstream;
using std::ostringstream;
using std::string;
using std::stringstream;
using std::vector;

//从文件读入到string里
string readFileIntoString(const char *filename);

//读文件到vector<string>
vector<string> readFileLines(const char *pathname);
//将字符串分隔
void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c);