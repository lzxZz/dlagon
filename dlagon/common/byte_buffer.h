/**
 * @file byte_buffer.h
 * @author lzxZz (616281384@qq.com)
 * @brief 字节缓存, 用于缓存字节数组, 来替代原先中大量string操作.
 * @version 0.1
 * @date 2019-05-26
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LZX_DLAGON_COMMMON_BYTE_BUFFER_H_
#define LZX_DLAGON_COMMMON_BYTE_BUFFER_H_


#include <vector>


namespace lzx::dlagon{
    using Byte = unsigned char;
    constexpr unsigned int BuffSize = 4096;
    using Block = Byte[BuffSize];
    using Size = std::size_t;
    
    class ByteBuffer{
    friend class BufferIterator;
    private:
        std::vector<Block> infos_;
        Size block_count_;
        Size final_block_size_;
    };

    class BufferIterator{
        
    };
}


#endif //LZX_DLAGON_COMMMON_BYTE_BUFFER_H_