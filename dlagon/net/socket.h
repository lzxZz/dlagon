/**
 * @file socket.h
 * @author lzxZz (616281384@qq.com)
 * @description Socket基础类
 * @version 0.1
 * @date 2019-04-14
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#include <memory>

namespace lzx::dlagon::net{

inline 
namespace core{

/**
 * @description 用于测试Socket类中是否会对套接字进行正确的释放
 * 新建一个套接字的时候， 将会对计数器+1
 * 释放一个套接字的时候， 将会对计数器-1
 */
#ifdef DLAGON_TEST_
    int dlagon_test_socket_release_count_ = 0;
    void dlagon_test_socket_release(){
        ++dlagon_test_socket_release_count_;
    }
    void dlagon_test_socket_new(){
        --dlagon_test_socket_release_count_;
    }

#endif
    
    /**
     * @description 使用shared_ptr管理套接字描述符
     * 
     * 使用组合， 而不是继承来使用套接字
     */
    class Socket{
    private:
        /**
         * @description 释放占用的套接字描述符
         * 
         * @param fd 
         */
        static void release_socket_fd(const int* const pfd);
    public:
        Socket(int fd) 
            : fd_ptr_(new int{fd}, release_socket_fd) 
            {
#ifdef DLAGON_TEST
                dlagon_test_socket_new();
#endif
            }
        Socket(const Socket &sock)
            : fd_ptr_{sock.fd_ptr_}
            {}
    private:
        
        
        std::shared_ptr<int> fd_ptr_;
    };

}

}