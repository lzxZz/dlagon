#include "dlagon/http/midware/static_file.h"

#include <unistd.h>

#include "dlagon/interface/midware.h"

using lzx::dlagon::interface::Midware;
using lzx::dlagon::interface::Request;
using lzx::dlagon::interface::Response;


#include "dlagon/http/request.h"

using std::string;
namespace lzx::dlagon::http::midware{

    Midware::MidwareState StaticFileMidWare::Handler(const Request &req, Response &res){
        
        Request req_ = req;
        HttpRequest &request = dynamic_cast<HttpRequest&>(req_);
        
        string path = root_dir_ + request.Head().Uri().substr(1); // substr(1), 用于去除路径中的首个点, // TODO 需要判断点是否存在

        // TODO
        if (access(path.c_str(), F_OK) == 0){
            
        }else{
            
        }
        return MidwareState::kStop;
    }
}