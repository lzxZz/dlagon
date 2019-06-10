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
   /**
    * @brief  静态文件中间件, 作为半个路由中间件, 
    * 
    * 持有一个静态资源池缓存对象, 和一个静态资源模式对象.  // TODO
    * 
    * 对于模式匹配的资源在本中间件处理. 要么返回静态资源, 要么返回404
    * 
    * 对于模式匹配失败的部分, 传递到下一个中间件.
    * 
    */
   class StaticFileMidWare : public lzx::dlagon::interface::Midware{
   public:
      StaticFileMidWare(const std::string root_dir) // TODO 将root_dir 替换为模式匹配对象
         : root_dir_(root_dir) {}
      lzx::dlagon::interface::Midware::MidwareState Handle(const lzx::dlagon::interface::Request &req,  lzx::dlagon::interface::Response &res) override;
      ~StaticFileMidWare(){}
   private:
      std::map<std::string, std::string> buf_;
      std::string root_dir_;
   };
}


#endif //LZX_DLAGON_HTTP_MIDWARE_STATIC_FILE_H_