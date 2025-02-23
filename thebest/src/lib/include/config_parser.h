#ifndef THEBEST_CONFIG_PARSER_H
#define THEBEST_CONFIG_PARSER_H

#include "thebest/iconfig_parser.h"

namespace TheBest
{

class ConfigParser : public virtual IConfigParser
{
public:
   std::expected<bool,std::string> parse(std::filesystem::path path) override;
   //...
};

} // namespace TheBest

#endif // THEBEST_CONFIG_PARSER_H