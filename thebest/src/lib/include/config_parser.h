#ifndef THEBEST_CONFIG_PARSER_H
#define THEBEST_CONFIG_PARSER_H

#include "thebest/iconfig_parser.h"

namespace TheBest
{

class ConfigParser : public virtual IConfigParser
{
public:
   std::expected<bool, std::string> parse(std::filesystem::path path) override;

#ifdef USE_FILESYSIO_LIB
   std::expected<bool, std::string> parse2(std::filesystem::path path, FileSysIo::IFileService& fileService) override;
#endif
};

} // namespace TheBest

#endif // THEBEST_CONFIG_PARSER_H