// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.24

/*
    对`http/request.h`的实现
*/

#include "http/request.h"

#include <string>
#include <sstream>
#include <unordered_map>

#include "http/header.h"

using std::string;
using std::unordered_map;
namespace dlagon {

namespace http {

    bool operator==(const HttpRequest &lhs, const HttpRequest &rhs)
    {
        return (lhs.Header() == rhs.Header() && lhs.Body() == rhs.Body());
    }
    bool operator!=(const HttpRequest &lhs, const HttpRequest &rhs)
    {
        return !(lhs == rhs);
    }
  

    /**
     *
     *  返回的请求中请求体部分,每行以\n结尾.
     * 
    **/
    HttpRequest HttpRequest::Parse(const string &str)
    {
        using std::istringstream;

        istringstream is(str);
        
        string head;

        getline(is, head);

        string m, p, v;

        istringstream head_input(head);
        head_input >> m >> p >> v;
        

        string line;
        unordered_map<string, string> args;
        using std::make_pair;
        while (getline(is, line))
        {
            //请求头和请求体之间用一个\r\n分割,二getline会吃掉一个\n
            if (line == "\r")
            {
                break;
            }
            string k, v;
            k = line.substr(0, line.find(":"));
            v = line.substr(line.find(":") + 1);
            args.emplace(make_pair(k, v));
        }
        string body;
        while (getline(is, line))
        {
            body.append(line);
            body.append("\n");
        }
        HttpRequestHeader req_head = HttpRequestHeader{StringToMethod(m), Path{p}, v, std::move(args)};
        return HttpRequest{req_head, body};


    }
}   //namespace http


}  // namespace dlagon
