#include "thebest/facade.h"
#include "thebest/iconfig_parser.h"
#include "ts_common.h"
#include "fake_factory.h"
#include "ts_config/parse.h"

namespace TsConfig
{

bool ParseTest1::run()
{
	TsCommon::outputTestInfo("Starting ParseTest1");

	// arrange
	TsCommon::FakeFactory fakeFactory;
	TheBest::Facade::create(fakeFactory);

	std::unique_ptr<TheBest::IConfigParser> configParser =
		TheBest::Facade::instance().factory().createConfigParser();

	// act
	const auto result = configParser->parse("ts_artifacts/config1.xml");

	// assert
	bool pass{};

	if (result.has_value())
	{
		pass = result.value();
	}
	else
	{
		pass = false;
		TsCommon::outputTestError("ParseTest1: " + result.error());
	}
	TsCommon::outputTestResult(pass, "ParseTest1");

	return pass;
}

} // namespace TsConfig
