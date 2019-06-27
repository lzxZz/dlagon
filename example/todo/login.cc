#include "example/todo/login.h"

#include "dlagon/http/request.h"
#include "dlagon/http/response.h"

#include <map>
#include <string>
#include <iostream>
using namespace lzx::dlagon::http;
using namespace std;
namespace lzx::dlagon::example::todo{
    // map<string, string> id_pass;
    void Init(const string &file){
        id_pass.emplace(make_pair("user", "pass"));
    }
    void Login(const HttpRequest &req, HttpResponse &res){  
        cout << "login"  << endl;
        switch (req.Head().Type()){
            case HttpMethod::kGet :{
                res = HttpResponse::HTTP_HTML_405.Clone();

                res.Argument().Set("CharSet", "UTF-8");
                res.Argument().Set("Content-Type", "text/html");
                res.SetBody("<meta charset=\"utf-8\">不支持GET方法<br>");
                cout << "get end" << endl;
                break;
            }
            case HttpMethod::kPost :{
                // 验证密码
                string id, pass;

                auto id_result = req.PostArgument().Get("ID");
                auto pass_result = req.PostArgument().Get("PASS");
                

                if (id_result.Valid() != ResultType::Ok || pass_result.Valid() != ResultType::Ok){
                    res = HttpResponse::HTTP_HTML_400.Clone();
                    res.Argument().Set("CharSet", "UTF-8");
                    res.Argument().Set("Content-Type", "text/html");
                    res.SetBody("<meta charset=\"utf-8\">帐号密码参数传递失败<br>");
                }

                id = id_result.Value();
                pass = pass_result.Value();

                auto iter = id_pass.find(id);

                if (iter != id_pass.end()){
                    if (pass == iter->second){
                        res = HttpResponse::HTTP_HTML_200.Clone();
                        res.Argument().Set("CharSet", "UTF-8");
                        res.Argument().Set("Content-Type", "text/html");
                        res.SetBody("<meta charset=\"utf-8\">登录成功<br>");   


                    }else{
                        res = HttpResponse::HTTP_HTML_200.Clone();
                        res.Argument().Set("CharSet", "UTF-8");
                        res.Argument().Set("Content-Type", "text/html");
                        res.SetBody("<meta charset=\"utf-8\">密码, 请重试<br>");    
                    }
                }else{
                    res = HttpResponse::HTTP_HTML_200.Clone();
                    res.Argument().Set("CharSet", "UTF-8");
                    res.Argument().Set("Content-Type", "text/html");
                    res.SetBody("<meta charset=\"utf-8\">id不存在, 请重试<br>");
                }
                break;
            }default :{
                res = HttpResponse::HTTP_HTML_501.Clone();
                break;
            }
        }
    }
}