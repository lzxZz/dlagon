#include "../include/server.h"

#include "http/arg.h"

using namespace dlagon;

#include <iostream>
#include <string>
#include <unistd.h>
using std::cout;
using std::endl;
using std::string;

string root_dir = "/media/disk/StudyFile/Project/dlagon/static";
Http_Response index(Http_Request)
{
    Http_Response response("HTTP/1.1", 200, "OK");
    response.header.emplace("Content-Type", "text/html");
    response.set_body_by_content("<h1>Index Page</h1>");

    return response;
}
Http_Response any(Http_Request req)
{
    Http_Response res{"HTTP/1.1", 404, "NOTFOUND"};

    res.header.emplace(std::make_pair("Content-Type", "text/html"));
    res.set_body_by_content("<meta charset=\"utf8\"><h1>请求的资源不存在</h1>");
    if (access((root_dir + req.path).c_str(), F_OK) == 0)
    {
        res = Http_Response{"HTTP/1.1", 200, "OK"};
        string suffix = req.path.substr(req.path.find_last_of("."));
        for (char &c : suffix)
        {
            c = toupper(c);
        }
        if (suffix == "CSS")
        {
            res.header.emplace(std::make_pair("Content-Type", "text/css"));
        }
        else if (suffix == "JS")
        {
            res.header.emplace(std::make_pair("Content-Type", "application/x-javascript"));
        }
        else if (suffix == "JPG" || suffix == "JPEG")
        {
            res.header.emplace(std::make_pair("Content-Type", "image/jpeg"));
        }
        else if (suffix == "PNG")
        {
            res.header.emplace(std::make_pair("Content-Type", "image/png"));
        }
        else if (suffix == "ICO")
        {
            res.header.emplace(std::make_pair("Content-Type", "image/x-icon"));
        }
        res.set_body(root_dir + req.path);

        return res;
    }
    return res;
}

Http_Response login(Http_Request req)
{

    Http_method method = req.method;
    if (method == Http_method::POST)
    {
        string body = req.body;
        cout << body << endl;
        // vector<string> infos ;
        // split(infos, body, is_any_of("\r\n"), token_compress_on);
        // unordered_map<string, string> dict;
        // for (auto line : infos)
        // {
        //     string key = line.substr(0,line.find(":"));
        //     string value = line.substr(line.find(":")+1);
        //     cout << "key = " << key << endl;
        //     cout << "value = " << value << endl;
        //     dict.emplace(std::make_pair(key, value));
        // }
    }
    else
    {
        Http_Response res{"HTTP/1.1", 200, "OK"};
        res.header.emplace("Content-Type", "text/html");
        res.set_body_by_content("<h1>Must use the POST Method!</h1>");

        return res;
    }
    Http_Response res{"HTTP/1.1", 200, "OK"};
        res.header.emplace("Content-Type", "text/html");
        res.set_body_by_content("<h1>Must use the POST Method!</h1>");

        return res;
}
int main()
{

    Server server{root_dir, 8080};
    server.add_path(Path{"/index.html"}, index)
        .add_path(Path{"/1/"}, index)
        .add_path(Path{"/login"}, login)
        .add_path(Path{"*"}, any)
        .allow_path("(/[a-z.]*)*")          //用于允许指定的访问. >>>注意需要添加一个/,所有的访问请求都是从根目录开始的<<<
        .run(8080);
}