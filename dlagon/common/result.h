#ifndef LZX_DLAGON_COMMON_RESULT_H_
#define LZX_DLAGON_COMMON_RESULT_H_

namespace lzx::dlagon{
    enum class ResultType{
        Ok,
        Err,
    };


    /**
     * @brief 仿照Rust中result枚举类型, 用于获取函数的返回状态和返回值.
     *  典型的用于HttpArgument中的Get方法, 来避免使用指针进行返回. (因为参数对应的值存在和错误返回值一样的情况.)
     * @tparam T 
     */
    template<typename T>
    class Result{
    public:
        Result() = delete; // 删除构造函数, 只允许使用静态函数构造对象.
        const ResultType Valid() const{
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