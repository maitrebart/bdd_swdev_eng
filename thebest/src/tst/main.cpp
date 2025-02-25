#include "ts_config/parse.h"
#include "ts_common.h"

int main(int argc, const char** argv)
{
   bool success(true);

	//success = success && 
	TsConfig::ParseTest1().run();
#ifdef USE_FILESYSIO_LIB
	//success = success && 
	TsConfig::ParseTest2().run();
#endif
	//...
	
   TsCommon::outputOverallResult(success);

	return success ? 0 : 1;
}
