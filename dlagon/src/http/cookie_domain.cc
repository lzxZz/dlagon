#include "http/cookie_domain.h"



using std::string;
using std::vector;


using boost::split;
using boost::is_any_of;

#include <iostream>
#include "common/debug.h"

using std::cout;

namespace dlagon{

namespace http{

    CookieDomain::CookieDomain(const string &domain_str){
        DLAGON_CALL_DEBUG;
        vector<string> domains;
        split(domains, domain_str, is_any_of("."));

        for (auto it = domains.rbegin(), end = domains.rend(); it != end; it++){
            domain_list_.push_back(*it);
        }
    }

    string CookieDomain::ToString(){
        DLAGON_CALL_DEBUG;
        string result;
        for (auto it = domain_list_.rbegin(), end = domain_list_.rend(); it != end; it++){
            result.append(".");
            result.append(*it);
        }
        result = result.substr(1);
        return result;
    }

    void CookieDomain::AddSubDomain(const string &sub_domain){
        DLAGON_CALL_DEBUG;
        domain_list_.push_back(sub_domain);
    }

    bool CookieDomain::PartOf(const CookieDomain &domain){
        DLAGON_CALL_DEBUG;
        if (domain_list_.size() < domain.domain_list_.size()){
            return false;
        }
        for (vector<string>::size_type i = 0; i < domain.domain_list_.size(); i++){
            if (this->domain_list_[i] != domain.domain_list_[i]){
                return false;
            }
        }
        return true;
    }

    bool CookieDomain::Contain(const CookieDomain &domain){
        DLAGON_CALL_DEBUG;
        if (this->domain_list_.size() > domain.domain_list_.size()){
            return false;
        }
        for (vector<string>::size_type i = 0; i < this->domain_list_.size(); i++){
            if (this->domain_list_[i] != domain.domain_list_[i]){
                return false;
            }
        }
        return true;
        
    }

    bool CookieDomain::operator==(const CookieDomain &domain) const{
        DLAGON_CALL_DEBUG;
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

    bool CookieDomain::operator!=(const CookieDomain &domain) const{
        DLAGON_CALL_DEBUG;
        return !(*this == domain);
    }


} //namespace http

} // namespace dlagon