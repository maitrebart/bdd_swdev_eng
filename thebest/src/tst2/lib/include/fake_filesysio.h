#ifndef FAKE_FILESYSIO_H
#define FAKE_FILESYSIO_H

#include "filesysio/ifile_service.h"

namespace FileSysIo
{

struct FakeFileService : public virtual IFileService
{
public:
   bool doesExist(const std::filesystem::path& path) override;
   EntryInfo getType(const std::filesystem::path& path) override;
   SizeType getSize(const std::filesystem::path& path) override;
   RwError read(const std::filesystem::path& path, ReadCallback readCallback) override;
   RwError write(const std::filesystem::path& path, WriteCallback writeCallback) override;
   // TODO: copy, move/rename, delete, lock

   std::stringstream m_readContent;
};

//class FakeDirService : public virtual IDirService
//{
//public:
//   bool create(const std::filesystem::path& path) override;
//   std::vector<std::string> list(const std::filesystem::path& path, bool recursive) override;
//   SizeType getNumEntries(const std::filesystem::path& path, bool recursive) override;
//   bool checkIfEmpty(const std::filesystem::path& path) override;
//   // TODO: Delete
//};
//
//class FakeFactory : public virtual IFactory
//{
//public:
//   FakeFactory(IFileService& fileService, IDirService& dirService);
//
//   IFileService& fileService() override;
//   IDirService& dirService() override;
//
//private:
//   IFileService& m_fileService;
//   IDirService& m_dirService;
//};

} // namespace FileSysIo

#endif // FAKE_FILESYSIO_H