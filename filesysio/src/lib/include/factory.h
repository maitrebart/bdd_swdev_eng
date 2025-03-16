#ifndef FSIO_FACTORY_H
#define FSIO_FACTORY_H

#include "filesysio/ifactory.h"

namespace FileSysIo
{

class Factory : public virtual IFactory
{
 public:
   Factory(IFileService& fileService, IDirService& dirService);

   IFileService& fileService() override;
   IDirService& dirService() override;

 private:
   IFileService& m_fileService;
   IDirService& m_dirService;
};

} // namespace FileSysIo

#endif // FSIO_FACTORY_H