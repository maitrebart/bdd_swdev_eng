#include "filesysio/facade.h"
#include "dir_service.h"
#include "factory.h"
#include "file_service.h"

namespace FileSysIo
{

Facade* Facade::s_pFacade = nullptr;

void
Facade::create()
{
   static FileService fileService;
   static DirService dirService;
   static Factory factory(fileService, dirService);
   create(factory);
}

void
Facade::create(IFactory& factory)
{
   static Facade facade(factory);
   s_pFacade = &facade;
}

Facade&
Facade::instance()
{
   return *s_pFacade;
}

Facade::Facade(IFactory& factory)
  : m_factory(factory)
{
}

IFactory&
Facade::factory()
{
   return m_factory;
}

} // namespace FileSysIo
