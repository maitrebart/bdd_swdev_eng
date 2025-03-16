#include "ts_common.h"
#include "ts_config/parse.h"

int
main(int argc, const char** argv)
{
   bool success(true);

   success = TsConfig::ParseTest1().run() && success;
#ifdef USE_FILESYSIO_LIB
   success = TsConfig::ParseTest2().run() && success;
#endif
   //...

   TsCommon::outputOverallResult(success);

   return success ? 0 : 1;
}
