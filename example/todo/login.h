#ifndef LZX_DLAGON_EXAMPLE_TODO_LOGIN_H_
#define LZX_DLAGON_EXAMPLE_TODO_LOGIN_H_

#include <map>
#include <string>

#include "dlagon/http/request.h"
#include "dlagon/http/response.h"

namespace lzx::dlagon::example::todo{
    using namespace lzx::dlagon::http;

    // 登录处理主函数
    void Login(const HttpRequest &req, HttpResponse &res);
    
    // 初始化服务器
    void Init(const std::string &count_file);

    
    // 存储用户密码数据
    static std::map<std::string, std::string> id_pass;

}

#endif //LZX_DLAGON_EXAMPLE_TODO_LOGIN_H_