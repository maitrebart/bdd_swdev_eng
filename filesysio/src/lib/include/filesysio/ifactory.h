#ifndef FSIO_IFACTORY_H
#define FSIO_IFACTORY_H

namespace FileSysIo
{

class IFileService;
class IDirService;

class IFactory
{
public:
   virtual IFileService& fileService() = 0;
   virtual IDirService& dirService() = 0;
};

} // namespace FileSysIo

#endif // FSIO_IFACTORY_H