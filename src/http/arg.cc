#include "http/arg.h"

#include <vector>

#include <boost/algorithm/string.hpp>

using boost::split;
using boost::is_any_of;

using std::string;
using std::vector;
using std::make_pair;

//参数列表中不同的参数使用&符号分割
dlagon::Argument::Argument(string s)
{
    vector<string> infos;
    split(infos, s, is_any_of("&"));
    for (auto arg : infos)
    {
        string key,value;
        key = arg.substr(0,arg.find("="));
        value = arg.substr(arg.find("=")+1);
        args.emplace(make_pair(key,value));
    }
}

string dlagon::Argument::find(string key)
{
    auto iter = args.find(key);
    if (iter != args.end())
    {
        return iter->second;
    }
    return "";
}

string dlagon::Argument::list()
{
    string result;
    for (auto i : args)
    {
        result.append(i.first);
        result.append(":");
        result.append(i.second);
        result.append("\n");
    }
    return result;
}