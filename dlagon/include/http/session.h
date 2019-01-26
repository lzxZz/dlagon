#ifndef DLAGON_HTTP_SESSION_H_
#define DLAGON_HTTP_SESSION_H_

#include <map>
#include <string>
#include <vector>

#include "http/http_request.h"


namespace dlagon{

namespace http{
    
    

    /**
     *
     *  Session类,用于在http通信过程中,保持一个访问记录
     *  
    **/
    class Session{
    public:
        explicit Session(std::string id)
            : id_(id) {}
        const std::vector<HttpRequest> Historical() const ;
        void AddHistorical(const HttpRequest req);
        
        const std::string ID() const;
        // 暂时不实现超时方法
        void TimeOut(const std::string time_out);
        const std::string TimeOut() const;
    private:
        const std::string id_;
        std::vector<HttpRequest> historical_;
        std::string time_out_;
    };


    class SessionCollection{
    public:
        // 可能返回空指针
        Session* Get(const std::string &key);
        const std::string New(HttpRequest req);
        const std::string New();
        void Remove(const std::string &key);

    private:
        std::map<const std::string, Session> collection_;
    };


} //namespace http

} //namespace dlagon

#endif //DLAGON_HTTP_SESSION_H_
