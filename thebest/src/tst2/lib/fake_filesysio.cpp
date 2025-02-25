#include "fake_filesysio.h"

namespace FileSysIo
{

bool FakeFileService::doesExist(const std::filesystem::path& path)
{
   return true;
}

EntryInfo FakeFileService::getType(const std::filesystem::path& path)
{
   return std::make_pair(EntryType::File,EntryType::File);
}

SizeType FakeFileService::getSize(const std::filesystem::path& path)
{
   return 42;
}

IFileService::RwError FakeFileService::read(const std::filesystem::path& path, ReadCallback readCallback)
{
   IFileService::RwError error;
   for (std::string line; std::getline(m_readContent, line); )
   {
      if (!readCallback(RwInfo{line, false}))
         break;
   }
   readCallback(RwInfo{{}, true});
   return error;
}

IFileService::RwError FakeFileService::write(const std::filesystem::path& path, WriteCallback writeCallback)
{
   return std::nullopt;
}

// TODO: copy, move/rename, delete, lock

//////////////////////////////////////////

//bool FakeDirService::create(const std::filesystem::path& path)
//{
//   return {};
//}
//
//std::vector<std::string> FakeDirService::list(const std::filesystem::path& path, bool recursive)
//{
//   return {};
//}
//
//SizeType FakeDirService::getNumEntries(const std::filesystem::path& path, bool recursive)
//{
//   return {};
//}
//
//bool FakeDirService::checkIfEmpty(const std::filesystem::path& path)
//{
//   return {};
//}

// TODO: Delete

//////////////////////////////////////////

//FakeFactory::FakeFactory(IFileService& fileService, IDirService& dirService) :
//   m_fileService(fileService),
//   m_dirService(dirService)
//{}
//
//IFileService& FakeFactory::fileService()
//{
//   return m_fileService;
//}
//
//IDirService& FakeFactory::dirService()
//{
//   return m_dirService;
//}

} // namespace FileSysIo
