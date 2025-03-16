#include "factory.h"
#include "config_parser.h"

namespace TheBest
{

std::unique_ptr<IConfigParser>
Factory::createConfigParser()
{
   return std::make_unique<ConfigParser>();
}

} // namespace TheBest
