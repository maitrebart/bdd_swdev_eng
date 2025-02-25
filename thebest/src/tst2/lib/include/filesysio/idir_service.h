#ifndef FSIO_IDIR_SERVICE_H
#define FSIO_IDIR_SERVICE_H

#include "filesysio/types.h"

namespace FileSysIo
{

class IDirService
{
public:
   virtual bool create(const std::filesystem::path& path) = 0;
   virtual std::vector<std::string> list(const std::filesystem::path& path, bool recursive) = 0;
   virtual SizeType getNumEntries(const std::filesystem::path& path, bool recursive) = 0;
   virtual bool checkIfEmpty(const std::filesystem::path& path) = 0;
   // TODO: Delete
};

} // namespace FileSysIo

#endif // FSIO_IDIR_SERVICE_H