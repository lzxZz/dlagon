#ifndef DLAGON_PATH_H_
#define DLAGON_PATH_H_

#include <string>

namespace dlagon
{
class Path
{
    std::string path;
public:
    Path(std::string p):path(p)
    {
        if ( *(p.end()-1) == '/')
        {
            path += "index.html";
        }
    }
    bool operator==(const Path &p)
    {
        
        return p.path == this->path;
    }
    bool operator==(const Path &p) const
    {
        return p.path == this->path;
    }
    bool operator!=(const Path &p)
    {
        return ! (p==*this);
    }
    bool operator!=(const Path &p) const
    {
        return ! (p==*this);
    }
};
} // namespace dlagon

#endif // DLAGON_PATH_H_