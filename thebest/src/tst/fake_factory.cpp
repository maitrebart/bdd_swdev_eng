#include "fake_factory.h"
#include "ts_config/fake_config_parser.h"

namespace TsCommon
{

std::unique_ptr<TheBest::IConfigParser>
FakeFactory::createConfigParser()
{
   return std::make_unique<TsConfig::FakeConfigParser>();
}

} // namespace TsCommon
