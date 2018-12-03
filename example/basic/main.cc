#include "dlagon.h"

using namespace dlagon;
std::string rootdir = "/media/disk/StudyFile/Project/dlagon/example/basic/static";

Http_Response index(Http_Request)
{
    Http_Response res{"HTTP/1.1", 200, "OK"};
    res.header.emplace("Content-Type", "text/html");
    res.set_body(rootdir + "/index.html");

    return res;
}



Http_Response any_page(Http_Request)
{
    Http_Response res{"HTTP/1.1", 200, "OK"};
    res.header.emplace("Content-Type", "text/html");
    res.set_body_by_content("<meta charset=\"utf8\"><h1>非主页</h1>");

    return res;
}

int main()
{
    Server server{rootdir, 8080};

    server.add_path(Path{"/index.html"}, index)
        .add_path(Path{"*"}, any_page)      //这里一定要求是星号,原因在于Server类中find_handler硬编码了==*
        .run();
}