// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.28

/*
    本文件声明的Path类,用于表示一个路径,
    目前作为HTTP请求头的组成部分.
*/

#ifndef DLAGON_COMMON_PATH_H_
#define DLAGON_COMMON_PATH_H_

#include <string>

namespace dlagon
{
    /*
    *   Path类,用于表示HTTP请求的资源路径.(暂定任务,目前看来有些多余)
    */
    class Path
    {
    public:
        explicit Path(const std::string path)
            : path_(path) {}
        Path &operator=(const dlagon::Path &path);
        // 返回路径表示的字符串
        auto ToString() const 
            -> const std::string 
        {
            return path_;
        }
    private:
        std::string           path_;    // 取消const属性,用于完成赋值运算符
    };
    bool operator==(const Path &lhs, const Path &rhs);
    bool operator!=(const Path &lhs, const Path &rhs);
} //namespace dlagon

#endif //DLAGON_COMMON_PATH_H_