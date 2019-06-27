#include "dlagon/web/id_pool.h"

using std::string;

namespace lzx::dlagon::web{
    const char numbers[] = {
        '0','1','2','3','4','5','6','7','8','9'
    };
    const char lowers[] = {
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
    };
    const char uppers[] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };
    const char alphas[] = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
    };
    const char lowers_numbers[] = {
        '0','1','2','3','4','5','6','7','8','9',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
    };
    const char uppers_numbers[] = {
        '0','1','2','3','4','5','6','7','8','9',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };
    const char number_alphas[] = {
        '0','1','2','3','4','5','6','7','8','9',
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };    


    // TODO 需要错误处理, 

    const string RandomString(int length, IdPool::IdRangeType type){
        const char *array;
        int size;
        switch (type){
            case IdPool::IdRangeType::kNumber:{
                array = numbers;
                size = sizeof(numbers);
                break;
            }
            case IdPool::IdRangeType::kLowerCase:{
                array = lowers;
                size = sizeof(lowers);
                break;
            }
            case IdPool::IdRangeType::kUpperCase:{
                array = uppers;
                size = sizeof(uppers);
                break;
            }
            case IdPool::IdRangeType::kNumLower:{
                array = lowers_numbers;
                size = sizeof(lowers_numbers);
                break;
            }
            case IdPool::IdRangeType::kNumUpper:{
                array = uppers_numbers;
                size = sizeof(uppers_numbers);
                break;
            }
            case IdPool::IdRangeType::kAlpha:{
                array = alphas;
                size = sizeof(alphas);
                break;
            }
            case IdPool::IdRangeType::kNumAlpha:{
                array = number_alphas;
                size = sizeof(number_alphas);
                break;
            }
        }

        string result;

        for (auto i = 0; i < length; i++){
            int index = rand() % size;
            result += array[index];
        }

        return result;
    }
     
    string IdPool::GeneralRandomString(int length, IdPool::IdRangeType type){
        int falid_times = 0;

        while(falid_times < 10){
            int old_size = id_pool_.size();
            // const string id = GeneralRandomString(length, type);
            const string id = RandomString(length, type);
            id_pool_.emplace(id);
            int new_size = id_pool_.size();

            if (new_size - old_size == 1){
                return id;
            }
        }

        return "";
    }

    void IdPool::ExpendPool(int size){
        
        try{
            for (auto i = 0 ; i < size; i++){
                string id = GeneralRandomString(id_length_);
                id_pool_.emplace(id);
                id_queue_.push_back(id);
            }

        }catch(std::exception *e){

        }

    }


    //  需要错误处理, 需要多线程保护
    void IdPool::ReducePool(int size){
        if (size > id_queue_.size()){

        }else{
            for (auto i = 0; i < size; i++){
                string id = id_queue_.front();
                id_queue_.pop_front();
                id_pool_.erase(id);
            }
        }
    }

    void IdPool::AutoReduce(){

    }
    void IdPool::AutoExpend(){

    }
}



























