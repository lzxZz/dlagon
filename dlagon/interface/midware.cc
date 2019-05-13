#include "dlagon/interface/midware.h"

#include "dlagon/interface/protocol/response.h"
#include "dlagon/interface/protocol/request.h"

namespace lzx::dlagon::interface{
   void Midware::WorkFlow(const Request &req, Response &res){
      MidwareState state =  Handler(req, res);

      if (state == MidwareState::kContinue){
         if (next_){
            next_->Handler(req, res);
         }
         
      }
      
   }


}