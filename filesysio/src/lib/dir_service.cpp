#include "dir_service.h"

namespace FileSysIo
{

bool
DirService::create(const std::filesystem::path& path)
{
   return {};
}

std::vector<std::string>
DirService::list(const std::filesystem::path& path, bool recursive)
{
   return {};
}

SizeType
DirService::getNumEntries(const std::filesystem::path& path, bool recursive)
{
   return {};
}

bool
DirService::checkIfEmpty(const std::filesystem::path& path)
{
   return {};
}

// TODO: Delete

} // namespace FileSysIo
