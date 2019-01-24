#ifndef DLAGON_COMMON_ARGUMENT_TABLE_H_
#define DLAGON_COMMON_ARGUMENT_TABLE_H_

#include <map>
#include <string>

namespace dlagon{

    class ArgumentTable{
    public:        
        const std::string Get(const std::string &key) const;
        ArgumentTable &Set(const std::string &key, const std::string &value);
        ArgumentTable &Clear();
        ArgumentTable &Remove(const std::string &key);
        const std::string ToString(const std::string split = ":") const;
    private:
        std::map<std::string, std::string>  arg_table_;
    };
} //namespace dlagon


#endif //DLAGON_COMMON_ARGUMENT_TABLE_H_