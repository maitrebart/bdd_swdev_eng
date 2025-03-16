#ifndef FSIO_IFACTORY_H
#define FSIO_IFACTORY_H

namespace FileSysIo
{
inline namespace V1_0_0
{

class IFileService;
class IDirService;

class IFactory
{
 public:
   virtual IFileService& fileService() = 0;
   virtual IDirService& dirService() = 0;
};

} // namespace V1_0_0
} // namespace FileSysIo

#endif // FSIO_IFACTORY_H