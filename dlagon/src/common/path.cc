// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2018.12.24

/*
    对`common/path.h`的实现
*/

#include "common/path.h"

namespace dlagon{
    
        bool operator==(const Path &lhs, const Path &rhs)
        {
            return (lhs.ToString() == rhs.ToString());
        }
        bool operator!=(const Path &lhs, const Path &rhs)
        {
            
            return !(lhs == rhs);
        }
   
} //namespace dlagon