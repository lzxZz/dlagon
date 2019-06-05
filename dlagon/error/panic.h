#ifndef LZX_DLAGON_ERROR_PANIC_H_
#define LZX_DLAGON_ERROR_PANIC_H_

#include <stdlib.h>

#include <string>
#include <iostream>

namespace lzx::dlagon::error{
    
    /**
     * @brief 输出信息到标准错误, 并终止程序
     * 
     * @param info 错误信息
     */
    void Panic(const std::string &info){
        std::cerr << info << std::endl;

        exit(-1);
        
    }
}

#endif //LZX_DLAGON_ERROR_PANIC_H_