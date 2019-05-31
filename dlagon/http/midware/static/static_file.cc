#include "dlagon/http/midware/static/static_file.h"

#include <unistd.h>

#include <fstream>

#include "dlagon/interface/midware.h"
#include "dlagon/http/request.h"
#include "dlagon/http/response.h"

using std::ifstream;
using std::string;

using lzx::dlagon::interface::Midware;
using lzx::dlagon::interface::Request;
using lzx::dlagon::interface::Response;


using lzx::dlagon::http::HttpResponse;


#include "dlagon/http/request.h"

#include <iostream>
using std::cout;
using std::endl;

namespace lzx::dlagon::http::midware{

    Midware::MidwareState StaticFileMidWare::Handler(const Request &req, Response &res) {
        const HttpRequest &request = dynamic_cast<const HttpRequest&>(req);
        
        string path = root_dir_ + request.Head().Uri(); // substr(1), 用于去除路径中的首个点, // TODO 需要判断点是否存在
        cout << path << endl;
        // TODO
        res = dynamic_cast<HttpResponse&>(res);
        if (access(path.c_str(), F_OK) == 0){
            
            res = HttpResponse::HTTP_HTML_200.Clone();
            ifstream input;
            input.open(path);
            if (input.is_open()){
                string line, content;
                while (getline(input, line)){
                    content += line + "\n";
                }
                res.SetBody(new HttpResponseBody(content));
            }else{
                res = HttpResponse::HTTP_HTML_404.Clone();
                res.SetBody(new HttpResponseBody("读取文件失败"));    
            }
            
        }else{
            res = HttpResponse::HTTP_HTML_404.Clone();
            res.SetBody(new HttpResponseBody("请求的文件不存在"));
        }
        return MidwareState::kStop;
    }
}