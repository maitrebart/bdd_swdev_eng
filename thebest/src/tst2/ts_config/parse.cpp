#include "ts_config/parse.h"
#include "fake_factory.h"
#include "fake_filesysio.h"
#include "thebest/facade.h"
#include "thebest/iconfig_parser.h"
#include "ts_common.h"

namespace fio = FileSysIo;

namespace TsConfig
{

bool
ParseTest1::run()
{
   TsCommon::outputTestInfo("Starting ParseTest1");

   // arrange
   TsCommon::FakeFactory fakeFactory;
   TheBest::Facade::create(fakeFactory);

   std::unique_ptr<TheBest::IConfigParser> configParser = TheBest::Facade::instance().factory().createConfigParser();

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

bool
ParseTest2::run()
{
   TsCommon::outputTestInfo("Starting ParseTest2");

   // arrange (thebest)
   TsCommon::FakeFactory fakeFactory;
   TheBest::Facade::create(fakeFactory);
   std::unique_ptr<TheBest::IConfigParser> configParser = TheBest::Facade::instance().factory().createConfigParser();

   // arrange (filesysio)
   fio::FakeFileService fakeFileService;
   fakeFileService.m_readContent << "This\n"
                                 << "is\n"
                                 << "a\n"
                                 << "test";

   // act
   const auto result = configParser->parse2("ts_artifacts/config1.xml", fakeFileService);

   // assert
   bool pass{};

   if (result.has_value())
   {
      pass = result.value();
   }
   else
   {
      pass = false;
      TsCommon::outputTestError("ParseTest2: " + result.error());
   }
   TsCommon::outputTestResult(pass, "ParseTest2");

   return pass;
}

} // namespace TsConfig
