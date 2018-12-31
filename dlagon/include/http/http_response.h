#ifndef DLAGON_HTTP_RESPONSE_H_
#define DLAGON_HTTP_RESPONSE_H_

#include "http/header.h"

namespace dlagon{

namespace http{

   class HttpResponse{
   public:
      HttpResponse(HttpResponseHeader header, std::string body)
         : header_(header), body_(body) {}

      std::string ToString() const;
      const HttpResponseHeader Header() const;
      const std::string        Body() const;
   private:
      const HttpResponseHeader   header_;
      const std::string          body_;
   };
}

} //namespace
#endif //DLAGON_HTTP_RESPONSE_H_