#ifndef FSIO_IFILE_SERVICE_H
#define FSIO_IFILE_SERVICE_H

#include "filesysio/types.h"

namespace FileSysIo
{

class IFileService
{
public:
   struct RwInfo
   {
      std::string line;
      bool isEof = false;
   };
   
   using ReadCallback = std::function<bool(RwInfo)>;
   using WriteCallback = std::function<RwInfo()>;
   using RwError = std::optional<std::string>;
   
   virtual bool doesExist(const std::filesystem::path& path) = 0;
   virtual EntryInfo getType(const std::filesystem::path& path) = 0;
   virtual SizeType getSize(const std::filesystem::path& path) = 0;
   virtual RwError read(const std::filesystem::path& path,
                         ReadCallback readCallback) = 0;
   virtual RwError write(const std::filesystem::path& path,
                          WriteCallback writeCallback) = 0;
   // TODO: copy, move/rename, delete, lock
};

} // namespace FileSysIo

#endif // FSIO_IFILE_SERVICE_H