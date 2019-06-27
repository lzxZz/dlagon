#include "dlagon/http/argument.h"

#include <map>
#include <set>
#include <string>

#include "boost/algorithm/string.hpp"


using std::set;
using std::string;


using lzx::dlagon::interface::Argument;
using lzx::dlagon::interface::ArgumentFactory;

using boost::is_any_of;
using boost::split;


namespace lzx::dlagon::http{
   HttpArgumentFactory *HttpArgumentFactory::factory_ = nullptr;

   bool operator==(const HttpArgument &lhs, const HttpArgument &rhs){
      return (lhs.args_ == rhs.args_);
   }
   bool operator!=(const HttpArgument &lhs, const HttpArgument &rhs){
      return !(lhs == rhs);
   }

   Argument *HttpArgumentFactory::FromString(const string &str){
      HttpArgument *arg = new HttpArgument();
      if (str == ""){
         return arg;
      }

      set<string> lines;

      split(lines, str, is_any_of("\n"));
      for (auto line : lines){
         string key, value;

         key = line.substr(0, line.find(":"));
         value = line.substr(line.find(":") + 1);
         arg->args_.emplace(make_pair(key, value));
      }
      return arg;
   }

   Argument *HttpArgumentFactory::FromString(const set<string> &str){
      HttpArgument *arg = new HttpArgument();
      if (str.size() == 0){
         return arg;
      }
      for (auto line : str){
         string key, value;

         key = line.substr(0, line.find(":"));
         value = line.substr(line.find(":") + 1);
         arg->args_.emplace(make_pair(key, value));
      }
      return arg;
   }

   const string HttpArgument::ToString() const{
      string result;

      for (auto iter : args_){
         result += iter.first + ":" + iter.second + "\r\n";
      }
      return result;
   }

   const Result<string> HttpArgument::Get(const string &key) const{
      auto iter = args_.find(key);
      
      if (iter == args_.end()){
         return Result<string>::NewErr("不存在的参数名"); // 对Result的使用
      }else{
         return Result<string>::NewOk(iter->second);
      }
   }
}
