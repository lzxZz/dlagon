#include "common/argument_table.h"
#include "common/debug.h"
using std::string;

namespace dlagon{

    const string  ArgumentTable::Get(const string &key) const{
        DLAGON_CALL_DEBUG;
        auto iter = arg_table_.find(key);

        if (iter == arg_table_.end()){
            return "";
        }
        return iter->second;
    }

    ArgumentTable &ArgumentTable::Set(const string &key, const string &value){
        DLAGON_CALL_DEBUG;
        arg_table_.emplace(std::make_pair(key, value));
        return *this;
    }

    ArgumentTable &ArgumentTable::Clear(){
        DLAGON_CALL_DEBUG;
        arg_table_.clear();
        return *this;
    }

    ArgumentTable &ArgumentTable::Remove(const string &key){
        DLAGON_CALL_DEBUG;
        auto iter = arg_table_.find(key);
        if (iter != arg_table_.end()){
            arg_table_.erase(iter);
        }
        return *this;
    }
    const string ArgumentTable::ToString(const string split) const{
        DLAGON_CALL_DEBUG;
        string info;
        for (auto iter : arg_table_){
            info.append(iter.first);
            info.append(split);
            info.append(iter.second);
            info.append("\r\n");
        }
        return info;
    }

} //namespace dlagon