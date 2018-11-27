 #include "../include/server.h"

using namespace dlagon;

Http_Response index(Http_Request)
{
    Http_Response response("HTTP/1.1",200, "OK");
    response.header.emplace("Content-Type","text/html");
    response.set_body_by_content("<h1>Index Page</h1>");

    return response;
}
Http_Response any(Http_Request)
{
    Http_Response response("HTTP/1.1",404, "NOT FOUND");
    response.header.emplace("Content-Type","text/html");
    response.set_body_by_content("<meta charset=\"utf8\"><h1>请求资源不存在</h1>");

    return response;
}

int main(){
    Server server{"/media/disk/StudyFile/Project/dlagon/static",8080};
    server.add_path(Path{"/index.html"}, index)
        .add_path(Path{"/1/"},index)
        .add_path(Path{"*"}, any)
        .run(8080);
    
}