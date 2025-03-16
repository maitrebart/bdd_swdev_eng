#ifndef THEBEST_FACTORY_H
#define THEBEST_FACTORY_H

#include "thebest/ifactory.h"

namespace TheBest
{

class Factory : virtual public IFactory
{
 public:
   std::unique_ptr<IConfigParser> createConfigParser() override;
   //...
};

} // namespace TheBest

#endif // THEBEST_FACTORY_H