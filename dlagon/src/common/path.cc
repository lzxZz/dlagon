// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.24

/*
    对`common/path.h`的实现
*/

#include "common/path.h"
#include "common/debug.h"

using std::string;

namespace dlagon{
    const string Path::ToString() const{
        DLAGON_CALL_DEBUG;
        return path_;
    }

    Path &Path::operator=(const Path &path){
        DLAGON_CALL_DEBUG;
        this->path_ = path.path_;
        return *this;
    }
    
    bool operator==(const Path &lhs, const Path &rhs)
    {
        DLAGON_CALL_DEBUG;
        return (lhs.ToString() == rhs.ToString());
    }
    bool operator!=(const Path &lhs, const Path &rhs)
    {
        DLAGON_CALL_DEBUG;
        
        return !(lhs == rhs);
    }

} //namespace dlagon