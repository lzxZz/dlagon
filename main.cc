
#include <string>
#include "dlagon/http/request.h"
#include "dlagon/http/protocol_factory.h"
using namespace std;
using namespace lzx::dlagon::http;


string cookie_req = R"(GET /index.html HTTP/1.1
Host: www.baidu.com
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:66.0) Gecko/20100101 Firefox/66.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2
Accept-Encoding: gzip, deflate, br
Referer: https://offlintab.firefoxchina.cn/
Connection: keep-alive
Cookie: BAIDUID=38C52EB7B5C730C5967E038EEE6744CF:FG=1; BIDUPSID=38C52EB7B5C730C5967E038EEE6744CF; PSTM=1555997005; BD_UPN=13314752; sug=3; sugstore=0; ORIGIN=0; bdime=0; BDORZ=FFFB88E999055A3F8A630C64834BD6D0; H_PS_PSSID=1452_21118_29064_28519_29098_28724_28964_28835_28584_20718; H_PS_645EC=f10apUtxg9KuH7w%2BghtiaiOZfTOv7eNKaNYBAaE3qRGjPNClTnWl7qXfaHrHh3%2Bx%2BIUu; COOKIE_SESSION=32107_0_7_1_10_13_0_3_1_7_103_2_0_0_1_0_1558400483_0_1558432589%7C9%230_1_1557907026%7C1; delPer=0; BD_CK_SAM=1; PSINO=7; BDSVRTM=0
Upgrade-Insecure-Requests: 1)";



   


int main(){
   HttpRequest *req = dynamic_cast<HttpRequest*>
                     (HttpProtocolFactory
                        ::GetInstant()
                        ->RequestFromString(cookie_req));
   
   
}