#include "dlagon/http/argument.h"

#include <string>
#include <map>
#include <set>

#include "boost/algorithm/string.hpp"

using lzx::dlagon::interface::Argument;
using lzx::dlagon::interface::ArgumentFactory;

using std::set;
using std::string;

using boost::split;
using boost::is_any_of;
using std::make_pair;
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

   string HttpArgument::ToString(){
      return "";
   }

}
