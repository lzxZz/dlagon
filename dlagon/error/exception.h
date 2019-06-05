#ifndef LZX_DLAGON_ERROR_EXCEPTION_H
#define LZX_DLAGON_ERROR_EXCEPTION_H

#include <iostream>
#include <string>


namespace lzx::dlagon::exception{
    class Exception{
    public:
        Exception(const std::string &info) : information_(info){}

        virtual ~Exception(){}  
        virtual void What() const{
            std::cerr << information_ << std::endl;
        };
    private:
        std::string information_;
    };
}


#endif //LZX_DLAGON_ERROR_Excption_H