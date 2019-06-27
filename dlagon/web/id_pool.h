#ifndef LZX_DLAGON_WEB_ID_POOL_H_
#define LZX_DLAGON_WEB_ID_POOL_H_

#include <set>
#include <string>
#include <queue>


namespace lzx::dlagon::web{

/**
 * @brief 生成随机的id号, 用于id标识, 例如session等
 * 
 */
class IdPool{
    
public: 
    
    explicit IdPool(int id_length = 18) : id_length_(id_length) {}

    // 申请一个id
    const std::string ApplyId(){
        if (id_queue_.size() == 0){
            // 扩容
            ExpendPool(id_pool_.size() * kExpend_rate_); // 
        }else{
            std::string id = id_queue_.front();
            id_queue_.pop_front();
            return id;
        }
    }
    // 释放一个id
    void ReleaseId(const std::string &id){
        // 防止释放操作返回不存在的id. 并且扩容时分配此ID,导致id重复的问题
        id_pool_.emplace(id);           
        
        id_queue_.push_back(id);
    }

    // 手动增减ID池
    void ExpendPool(int size);
    void ReducePool(int size);
    
    // 自动增减ID池
    void AutoReduce();
    void AutoExpend();

    enum IdRangeType{
        kNumber = 1 << 0,
        kLowerCase = 1 << 1,
        kUpperCase = 1 << 2,
        kNumLower = kNumber + kLowerCase,
        kNumUpper = kNumber + kUpperCase,
        kAlpha = kLowerCase + kUpperCase,
        kNumAlpha = kNumber + kLowerCase + kUpperCase,
    };

    const int Capcity(){
        return id_pool_.size();
    }

    
private:
    std::string GeneralRandomString(int legnth, IdRangeType type = IdRangeType::kNumAlpha);
    std::deque<std::string> id_queue_; // id队列
    std::set<std::string> id_pool_; // id池

    int id_length_;
    const double kExpend_rate_ = 0.5;
};

}

#endif //LZX_DLAGON_WEB_ID_POOL_H_