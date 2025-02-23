#ifndef THEBEST_ICONFIG_PARSER_H
#define THEBEST_ICONFIG_PARSER_H

#include <memory>
#include <filesystem>
#include <expected>
#include <string>

namespace TheBest
{

class IConfigParser
{
public:
   virtual std::expected<bool,std::string> parse(std::filesystem::path path) = 0;
   //...
};

} // namespace TheBest

#endif // THEBEST_ICONFIG_PARSER_H