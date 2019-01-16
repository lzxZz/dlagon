// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.11

/*
    对`http/request.h`的实现
*/

#include "http/http_request.h"

#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>

#include "http/header.h"

#include <iostream>

using std::string;
using std::vector;
using std::unordered_map;
namespace dlagon {

namespace http {

    bool operator==( HttpRequest &lhs,  HttpRequest &rhs)
    {
        return (lhs.Header() == rhs.Header() && lhs.Body() == rhs.Body());
    }
    bool operator!=( HttpRequest &lhs,  HttpRequest &rhs)
    {
        return !(lhs == rhs);
    }

     bool operator==(const HttpRequest &lhs, const HttpRequest &rhs)
    {
        return (lhs.Header() == rhs.Header() && lhs.Body() == rhs.Body());
    }
    bool operator!=(const HttpRequest &lhs, const HttpRequest &rhs)
    {
        return !(lhs == rhs);
    }
  
    //去除空格
    void trim(string &s)
    {
        
        if( !s.empty() )
        {
            s.erase(0,s.find_first_not_of(" "));
            s.erase(s.find_last_not_of(" ") + 1);
        }
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
        ArgumentTable args;
        vector<Cookie> cookies;
        while (getline(is, line))
        {
            //请求头和请求体之间用一个\r\n分割,而getline会吃掉一个\n
            if (line == "\r")
            {
                break;
            }
            string k, v;
            k = line.substr(0, line.find(":"));
            v = line.substr(line.find(":") + 1);
            if(k == "Cookie"){
                vector<string> cookie_pairs;
                boost::split(cookie_pairs, v, boost::is_any_of(";"));
                string key, value;
                for (auto str : cookie_pairs){
                    key = str.substr(0, str.find("="));
                    value = str.substr(str.find("=") + 1);
                    
                    //去除cookie的首尾空格
                    trim(key);  
                    trim(value);
                    
                    cookies.push_back(Cookie{key,value});
                }
                
            }else{
                args.Set(k, v);
            }
            
        }
        string body;
        while (getline(is, line))
        {
            body.append(line);
            body.append("\n");
        }
        using Head = HttpRequestHeader;
        Head req_head = Head{StringToMethod(m), 
            Path{p}, v, 
            args};

        // std::cout << "cookie数量为:" << cookies.size() << "\n";
        // req_head.Cookies().insert(req_head.Cookies().begin(), cookies.begin(), cookies.end());
        for (auto cookie : cookies){
            req_head.AddCookie(cookie);
        }
        // std::cout << "++++++++++++++++\n";
        return HttpRequest{req_head, body};


    }
}   //namespace http


}  // namespace dlagon