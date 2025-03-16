#include "factory.h"
#include "thebest/facade.h"

#ifdef USE_FILESYSIO_LIB
#include "filesysio/facade.h"
#include "filesysio/ifactory.h"
#include "filesysio/ifile_service.h"
#endif // USE_FILESYSIO_LIB

#include <iostream>
#include <string>

int
main(int argc, const char** argv)
{
   using namespace TheBest;
   Facade::create();

   int result(0);
   // create other main classes,
   // passing interface to factory
   // via facade
   //...

#ifdef USE_FILESYSIO_LIB
   FileSysIo::Facade::create();

   static constexpr std::string CONFIG_FILE_NAME{ "config.xml" };
   const bool doesConfigFileExist{ FileSysIo::Facade::instance().factory().fileService().doesExist("config.xml") };
   std::cout << "The file " << CONFIG_FILE_NAME << (doesConfigFileExist ? " exists" : " does not exist") << "\n";
#endif // USE_FILESYSIO_LIB

   return result;
}
