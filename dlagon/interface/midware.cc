#include "dlagon/interface/midware.h"

#include "dlagon/interface/response.h"
#include "dlagon/interface/request.h"

namespace lzx::dlagon::interface{
   void Midware::WorkFlow(const Request &req, Response &res){
      bool continue_ = Handler(req, res);

      if (continue_){
         next_->Handler(req, res);
      }
      
   }


}