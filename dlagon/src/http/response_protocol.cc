// Copyright 2018, lzxZz
// e-mail : 616281384@qq.com
// last modified in 2019.1.1

/*
   对`http/response_protocol.h`的实现
*/
#include "http/response_protocol.h"
#include "common/debug.h"
using std::string;
namespace dlagon{

namespace http{

   const string HttpResponseProtocol::ToString() const{
        DLAGON_CALL_DEBUG;
      string info;
      info.append(version_);
      info.append("\t");
      info.append(std::to_string(state_code_));
      info.append("\t");
      info.append(state_info_);
      info.append("\n");
      return info;
   }
   //HttpResponseProtocol HTTP_RESPONSE_PROTOCOL_200{"HTTP/1.1", 200, "OK"};

} //namespace http

} //namespace dlagon