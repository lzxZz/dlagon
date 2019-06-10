#include "dlagon/common/log.h"

#include "dlagon/error/panic.h"

using std::endl;
using std::string;
namespace lzx::dlagon{
    void Log::Write(const string &info, LogLevel level){
        std::lock_guard<std::mutex> guard(mutex_);
        log_file_ << info << std::endl;
    }

    void Log::Init(const string &file){
        log_file_.open(file);
        if (!log_file_.is_open()){
            error::Panic("打开日志文件失败");
        }
        logger_ = new Log();
    }

    Log* Log::Logger(){
        return logger_;
    }
}