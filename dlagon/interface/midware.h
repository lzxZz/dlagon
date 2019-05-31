/**
 * @brief  中间件的定义, 使用职责链设计模式
 * 
 */

#ifndef LZX_DLAGON_INTERFACE_MIDWARE_H_
#define LZX_DLAGON_INTERFACE_MIDWARE_H_

namespace lzx::dlagon::interface{
   class Response;
   class Request;

   /**
    * @brief 服务器中间件抽象
    * 
    * 在服务器流程中， 会自动的沿着中间件链一直执行, 通过返回值判断是否继续执行
    * 
    */
   class Midware{
   public:
      enum class MidwareState{
         kStop,
         kContinue,
      };
   public:
      // 中间件的操作， 返回值指示是否需要继续执行
      virtual MidwareState Handler(const Request &req, Response &res) = 0;
      Midware &SetNext(Midware *next){
         next_ = next;
         return *this;
      }
      virtual ~Midware(){}
   private:
      // 中间件执行流程
      void WorkFlow(const Request &req, Response &res);
   protected:
      Midware *next_ = nullptr;
   };
}

#endif //LZX_DLAGON_INTERFACE_MIDWARE_H_