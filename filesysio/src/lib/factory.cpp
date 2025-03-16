#include "factory.h"

namespace FileSysIo
{

Factory::Factory(IFileService& fileService, IDirService& dirService)
  : m_fileService(fileService)
  , m_dirService(dirService)
{
}

IFileService&
Factory::fileService()
{
   return m_fileService;
}

IDirService&
Factory::dirService()
{
   return m_dirService;
}

} // namespace FileSysIo
