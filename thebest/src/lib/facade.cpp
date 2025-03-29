#include "thebest/facade.h"
#include "factory.h"
#include <stdexcept>

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
   if (&factory != &facade.factory())
   {
      throw std::runtime_error("Facade::create: a factory already exists; use replaceFactory()");
   }
   s_pFacade = &facade;
}

void
Facade::replaceFactory(IFactory& factory)
{
   if (s_pFacade == nullptr)
   {
      throw std::runtime_error("Facade::replaceFactory: Facade not created yet");
   }
   if (&factory != s_pFacade->m_pFactory)
   {
      s_pFacade->m_pFactory = &factory;
   }
}

Facade&
Facade::instance()
{
   return *s_pFacade;
}

Facade::Facade(IFactory& factory)
  : m_pFactory(&factory)
{
}

IFactory&
Facade::factory()
{
   if (m_pFactory == nullptr)
   {
      throw std::runtime_error("Facade::factory: factory not initialized");
   }
   return *m_pFactory;
}

// accessors to main classes' interface
//...

} // namespace TheBest
