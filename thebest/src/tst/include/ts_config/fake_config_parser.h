#ifndef FAKE_CONFIG_PARSER_H
#define FAKE_CONFIG_PARSER_H

#include "config_parser.h"

namespace TsConfig
{

// struct FakeConfigParser : public virtual TheBest::IConfigParser // override all methods
struct FakeConfigParser : public TheBest::ConfigParser // override specific methods
{
   //...
};

} // namespace TheBest

#endif // FAKE_CONFIG_PARSER_H