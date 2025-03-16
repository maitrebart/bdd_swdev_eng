#include "thebest/facade.h"
#include "factory.h"

namespace TheBest
{

Facade* Facade::s_pFacade = nullptr;

void
Facade::create()
{
   static Factory factory;
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

// accessors to main classes' interface
//...

} // namespace TheBest
