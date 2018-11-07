#include "../include/defs.h"

#include <vector>
#include <boost/algorithm/string.hpp>
#include <sstream>
#include <exception>

using boost::is_any_of;
using boost::split;
using boost::token_compress_on;
using std::istringstream;
using std::vector;
using std::exception;
using std::make_pair;
using namespace dlagon;
using std::string;

Http_request  dlagon::parse_to_request(const string &str)
{
    vector<string> lines;
    split(lines, str, is_any_of("\r\n"), token_compress_on);

    Http_request request;

    istringstream is(lines.at(0));          //可能抛出异常.out_of_range
    string method, path, version;
    is >> method >> path >> version;

    for (char &c : method)
    {
        if (islower(c))
        {
            c=toupper(c);
        }
    }

    if (method == "GET")
    {
        request.method = Http_method::GET;
    }
    else if (method == "POST")
    {
        request.method = Http_method::POST;
    }
    else if (method == "HEAD")
    {
        request.method = Http_method::HEAD;
    }
    else if (method == "DELETE")
    {
        request.method = Http_method::DELETE;
    }
    else if (method == "TRACE")
    {
        request.method = Http_method::TRACE;
    }
    else if (method == "PUT")
    {
        request.method = Http_method::PUT;
    }
    else if (method == "CONNECTION")
    {
        request.method = Http_method::CONNENCTION;
    }
    else
    {
        request.method = Http_method::OTHER;
    }
    request.method_str = method;
    request.path = path;
    request.version = version;

    for (auto line : lines)
    {
        if (line == *lines.begin())
        {
            continue;       //第一行已经处理过了,此处跳过
        }

        vector<string> values;
        split(values, line, is_any_of(":"));
        if (values.size() != 2)
        {
            continue;
            // throw exception{};      //如果按照冒号分割出来的结果不是键值对,抛出异常
        }
        request.header.emplace(make_pair(values[0],values[1]));
        
    }
    

    return request;
}

std::string dlagon::get_suffix(std::string path)
    {
        std::string suffix;
        suffix = path.substr(path.find_last_of('.')+1);
        for (char &c: suffix)
        {
            c=toupper(c);
        }
        return suffix;
    }