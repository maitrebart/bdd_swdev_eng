#ifndef THEBEST_FACTORY_H
#define THEBEST_FACTORY_H

#include "thebest/ifactory.h"

namespace TheBest
{
inline namespace V1_0_0
{

class Factory : virtual public IFactory
{
 public:
   std::unique_ptr<IConfigParser> createConfigParser() override;
   //...
};

} // namespace V1_0_0
} // namespace TheBest

#endif // THEBEST_FACTORY_H