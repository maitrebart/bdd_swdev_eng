#ifndef THEBEST_ICONFIG_PARSER_H
#define THEBEST_ICONFIG_PARSER_H

#include <expected>
#include <filesystem>
#include <iostream>
#include <memory>
#include <string>

#ifdef USE_FILESYSIO_LIB
#include "filesysio/ifile_service.h"
#endif // USE_FILESYSIO_LIB

namespace TheBest
{

class IConfigParser
{
public:
   virtual ~IConfigParser() = default;

   virtual std::expected<bool, std::string> parse(std::filesystem::path path) = 0;
   //...

#ifdef USE_FILESYSIO_LIB
   virtual std::expected<bool, std::string> parse2(std::filesystem::path path, FileSysIo::IFileService& fileService) = 0;
#endif
};

} // namespace TheBest

#endif // THEBEST_ICONFIG_PARSER_H