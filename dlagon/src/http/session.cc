#include "http/session.h"

using std::vector;
using std::string;

namespace dlagon{

namespace http{
    const vector<HttpRequest> Session::Historical() const{
        return historical_;
    }
    void Session::AddHistorical(const HttpRequest req){
        historical_.push_back(req);
    }


    Session* SessionCollection::Get(const string &key){
        auto iter = collection_.find(key);
        if (iter != collection_.end()){
            return &(iter->second);
        }
        // 没有找到则返回空指针
        return nullptr;
    }

    const char alphas[] = {'1','2','3','4','5','6','7','8','9','0',
                    'q','w','e','r','t','y','u','i','o','p',
                    'l','k','j','h','g','f','d','s','a',
                    'z','x','c','v','b','n','m',
                    'Q','W','E','R','T','Y','U','I','O','P',
                    'L','K','J','H','G','F','D','S','A',
                    'Z','X','C','V','B','N','M'};

    const string SessionCollection::New(){
       string key;
        srand(time(nullptr));
        
        do{
            key = "";
            for (int i = 0; i < 18; i++){
               int index = rand() % 62;
                    
               key += alphas[index];
            }
        }while(Get(key) != nullptr);
        Session session{key};
        
        collection_.emplace(std::make_pair(key, session));
        return key;
    }
    const std::string SessionCollection::New(HttpRequest req){
        string key = New();
        Session *session = Get(key);
        session->AddHistorical(req);
        return key;
    }

    void SessionCollection::Remove(const string &key){
        collection_.erase(key);
    }




} //namespace http

} //namespace dlagon