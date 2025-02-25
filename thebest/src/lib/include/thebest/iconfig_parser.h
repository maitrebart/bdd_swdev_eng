#ifndef THEBEST_ICONFIG_PARSER_H
#define THEBEST_ICONFIG_PARSER_H

#include <memory>
#include <filesystem>
#include <expected>
#include <string>
#include <iostream>

namespace FileSysIo
{
class IFileService;
}

namespace TheBest
{

class IConfigParser
{
public:
   virtual std::expected<bool,std::string> parse(std::filesystem::path path) = 0;
   //...

#ifdef USE_FILESYSIO_LIB
   virtual std::expected<bool,std::string> parse2(std::filesystem::path path, FileSysIo::IFileService& fileService) = 0;
#endif
};

} // namespace TheBest

#endif // THEBEST_ICONFIG_PARSER_H