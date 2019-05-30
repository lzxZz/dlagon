/**
 * @file static_file.h
 * @author lzxZz (616281384@qq.com)
 * @brief 静态文件缓存层中间件.
 * @version 0.1
 * @date 2019-05-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LZX_DLAGON_HTTP_MIDWARE_STATIC_FILE_H_
#define LZX_DLAGON_HTTP_MIDWARE_STATIC_FILE_H_

#include "dlagon/interface/midware.h"
#include <map>
#include <string>

namespace lzx::dlagon::http::midware{
   class StaticFileMidWare : public lzx::dlagon::interface::Midware{
   public:
      StaticFileMidWare(const std::string root_dir)
         : root_dir_(root_dir) {}
      MidwareState Handler(const lzx::dlagon::interface::Request &req,  lzx::dlagon::interface::Response &res);
   private:
      std::map<std::string, std::string> buf_;
      std::string root_dir_;
   };
}


#endif //LZX_DLAGON_HTTP_MIDWARE_STATIC_FILE_H_