#include "dlagon.h"

using namespace dlagon;

#include "string"

using namespace std;

int main(){

   
   try
   {
      cout << "启动" << endl;

      string root_dir;
      Server server;
      Route route{};
      
      server.SetRoute(route);
      server.Run(root_dir, 8080);
      
   }
   catch(const dlagon::exception::Exception& e)
   {
      std::cerr << e.What() << '\n';
   }
   return 0;
}