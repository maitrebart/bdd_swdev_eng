#ifndef FAKE_FACTORY_H
#define FAKE_FACTORY_H

#include "thebest/ifactory.h"

namespace TsCommon
{

struct FakeFactory : virtual public TheBest::IFactory
{
   std::unique_ptr<TheBest::IConfigParser> createConfigParser() override;
   //...
};

} // namespace TsCommon

#endif // FAKE_FACTORY_H