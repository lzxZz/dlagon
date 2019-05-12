#ifndef LZX_DLAGON_INTERFACE_MIDWARE_H_
#define LZX_DLAGON_INTERFACE_MIDWARE_H_

namespace lzx::dlagon::interface{
   class Response;
   class Request;

   /**
    * @brief 服务器中间件抽象
    * 
    * 在服务器流程中， 会自动的沿着中间件链一直执行, 如果处理完成了， 让Handler返回false即可
    * 
    */
   class Midware{
   public:
      // 中间件的操作， 返回值指示是否需要继续执行
      virtual bool Handler(const Request &req, Response &res) = 0;
   private:
      // 中间件执行流程
      void WorkFlow(const Request &req, Response &res);

      Midware *next_ = nullptr;
   };
}

#endif //LZX_DLAGON_INTERFACE_MIDWARE_H_