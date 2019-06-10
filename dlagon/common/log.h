#ifndef LZX_DLAGON_COMMON_LOG_H_
#define LZX_DLAGON_COMMON_LOG_H_

#include <fstream>
#include <string>
#include <mutex>
namespace lzx::dlagon{

enum class LogLevel{
    kTrace,
    kDebug,
    kInfo,
    kWarnning,
    kError,
    kFatal,
};

class Log{
public:
    void Write(const std::string &info,LogLevel level);
    static void Init(const std::string &file);
    static Log *Logger();
private:
    static std::ofstream log_file_;
    static Log *logger_;
    std::mutex mutex_;
};


}


#endif //LZX_DLAGON_COMMON_LOG_H_