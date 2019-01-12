#ifndef DLAGON_COOKIE_DOMAIN_H_
#define DLAGON_COOKIE_DOMAIN_H_

#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

namespace dlagon{

namespace http{

    class CookieDomain{
        
    public:

        CookieDomain() = default;
        // 将字符串表示的域名转为该类的对象
        CookieDomain(const std::string &domain_str);
        // 输出域名
        std::string ToString();

        // 给当前域名追加一个子域名,将范围缩小
        void AddSubDomain(const std::string sub_domain);

        //判断本域名是否包含参数所指定的域名
        bool Contain(const CookieDomain &domain);
        // 判断本域名是否属于参数表示的域名
        bool PartOf(const CookieDomain &domian);
        bool operator==(const CookieDomain &domain) const{
            if (this->domain_list_.size() != domain.domain_list_.size()){
                return false;
            }

            for (std::vector<std::string>::size_type i =0; i < domain.domain_list_.size(); i++){
                if (this->domain_list_[i]  != domain.domain_list_[i]) {
                    return false;
                }
            }
            
            return true;
        }
    private:

        // 使用vector来存储域名的各个级别，从顶级（com）开始存储,不存储点。但是在各个方法中输出点。
        std::vector<std::string> domain_list_;
    };

}   //namespace http

} //namespace dlagon


#endif //DLAGON_COOKIE_DOMAIN_H_