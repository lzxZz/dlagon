#include "dlagon/net/socket.h"
#include <unistd.h>

namespace lzx::dlagon::net{
inline
namespace core{
    void Socket::release_socket_fd(const int* const pfd){
        if (close(*pfd) != 0 ){
            // 异常处理

#ifdef DLAGON_TEST_
        dlagon_test_socket_release()；
#endif
        }
    }

}
}