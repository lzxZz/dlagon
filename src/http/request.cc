#include "http/request.h"

#include <vector>
#include <sstream>

#include <boost/algorithm/string.hpp>

using std::istringstream;
using std::string;
using std::vector;

using boost::is_any_of;
using boost::split;
using boost::token_compress_on;

using std::make_pair;

#include <iostream>
dlagon::Http_Request  dlagon::parse_to_request(const string &str)
{
    // std::cout << str << std::endl;


    Http_Request request;
    istringstream is(str);
    string protocal;
    getline(is, protocal);
    string line;

    //读取请求头
    while (getline(is, line))
    {
        //空行表示请求头结束,下面则是请求体
        if (line == "\r")
        {
            break;
        }
        string k,v;
        k = line.substr(0,line.find(":"));
        v = line.substr(line.find(":")+1);

        request.header.emplace(make_pair(k,v));

        // std::cout << "head"  << line << std::endl;
        
    }
     while (getline(is, line))
    {
        
        request.body.append(line);
        request.body.append("\n");
        //  std::cout << "body"  << line << std::endl;
    }
    


    

    is = istringstream{protocal};          //可能抛出异常.out_of_range
    string method, path, version;
    is >> method >> path >> version;

    for (char &c : method)
    {
        if (islower(c))
        {
            c = toupper(c);
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
    if (request.path.find("?") < 0)
    {
        path = path.substr(0, path.find("?"));
        string argstr = path.substr(path.find("&")+1);


        request.arg = Argument{argstr};
        request.path = path;
    }

    

    

    return request;
}