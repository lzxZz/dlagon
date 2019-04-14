#define DLAGON_TEST_
#include <gtest/gtest.h>

#include "dlagon/net/socket.h"

TEST(SocketTest, ReleaseCount){
    using namespace lzx::dlagon::net;
    {
        Socket sock{10};
        sock = Socket{1111};
    }
    ASSERT_EQ(0, dlagon_test_socket_release_count_);
}
