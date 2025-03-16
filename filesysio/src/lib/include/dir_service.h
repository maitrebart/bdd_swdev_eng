#ifndef FSIO_DIR_SERVICE_H
#define FSIO_DIR_SERVICE_H

#include "filesysio/idir_service.h"

#include <vector>

namespace FileSysIo
{
inline namespace V1_0_0
{

class DirService : public virtual IDirService
{
 public:
   bool create(const std::filesystem::path& path) override;
   std::vector<std::string> list(const std::filesystem::path& path, bool recursive) override;
   SizeType getNumEntries(const std::filesystem::path& path, bool recursive) override;
   bool checkIfEmpty(const std::filesystem::path& path) override;
   // TODO: Delete
};

} // namespace V1_0_0
} // namespace FileSysIo

#endif // FSIO_DIR_SERVICE_H