#ifndef LZX_DLAGON_COMMON_RESULT_H_
#define LZX_DLAGON_COMMON_RESULT_H_

namespace lzx::dlagon{
    enum class ResultType{
        Ok,
        Err,
    };
    template<typename T>
    class Result{
    public:
        Result() = delete;
        ResultType Valid(){
            return valid_;
        }
        static Result NewOk(T value){
            return Result(ResultType::Ok, value);
        }
        static Result NewErr(T value){
            return Result(ResultType::Err, value);
        }
        const T Value() const{
            return value_;
        }
    private:
        Result(ResultType type, T value)
            : valid_(type), value_(value) {}
        
        ResultType valid_;
        T value_;
    };
}

#endif //LZX_DLAGON_COMMON_RESULT_H_