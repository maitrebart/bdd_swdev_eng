#ifndef FSIO_FILE_SERVICE_H
#define FSIO_FILE_SERVICE_H

#include "filesysio/ifile_service.h"

namespace FileSysIo
{

class FileService : public virtual IFileService
{
 public:
   bool doesExist(const std::filesystem::path& path) override;
   EntryInfo getType(const std::filesystem::path& path) override;
   SizeType getSize(const std::filesystem::path& path) override;
   RwError read(const std::filesystem::path& path, ReadCallback readCallback) override;
   RwError write(const std::filesystem::path& path, WriteCallback writeCallback) override;
   // TODO: copy, move/rename, delete, lock
};

} // namespace FileSysIo

#endif // FSIO_FILE_SERVICE_H