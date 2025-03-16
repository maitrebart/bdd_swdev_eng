#ifndef THEBEST_IFACTORY_H
#define THEBEST_IFACTORY_H

#include <memory>

namespace TheBest
{
inline namespace V1_0_0
{

class IConfigParser;

class IFactory
{
 public:
   virtual std::unique_ptr<IConfigParser> createConfigParser() = 0;
   //...
};

} // namespace V1_0_0
} // namespace TheBest

#endif // THEBEST_IFACTORY_H