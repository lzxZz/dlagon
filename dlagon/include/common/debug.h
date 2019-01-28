#ifndef DLAGON_COMMON_DEBUG_H_
#define DLAGON_COMMON_DEBUG_H_

#include <iostream>

#define DEBUG // 开启调试选项, 注释该行可关闭调试选项

#ifdef DEBUG

#define DLAGON_OUT std::cout // 这里可以修改为std::err并将标准错误重定向到文件来隔离调用顺序和输出.

#define DLAGON_CALL_DEBUG DLAGON_OUT << ">>>>>>CALL BY:<<<<<<file:" << __FILE__ << "\n\t\t\tline:" << __LINE__ << "\t\t\tfunc:" << __func__ << std::endl

#else
#define DLAGON_DEBUG

#endif

#endif //DLAGON_COMMON_DEBUG_H_


