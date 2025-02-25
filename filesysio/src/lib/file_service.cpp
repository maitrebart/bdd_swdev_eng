#include "file_service.h"

namespace FileSysIo
{

bool FileService::doesExist(const std::filesystem::path& path)
{
   return {};
}

EntryInfo FileService::getType(const std::filesystem::path& path)
{
   return {};
}

SizeType FileService::getSize(const std::filesystem::path& path)
{
   return {};
}

FileService::RwError FileService::read(const std::filesystem::path& path, ReadCallback readCallback)
{
   return {};
}

FileService::RwError FileService::write(const std::filesystem::path& path, WriteCallback writeCallback)
{
   return {};
}

// TODO: copy, move/rename, delete, lock

} // namespace FileSysIo
