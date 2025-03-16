#ifndef THEBEST_FACADE_H
#define THEBEST_FACADE_H

namespace TheBest
{

class IFactory;
// forward-declarations of main classes' interface
//...

class Facade
{
 public:
   static void create(); // for thebest app (uses default factory)
   static void create(IFactory& factory); // for ext app or tst
   static Facade& instance();

   IFactory& factory();

   // accessors to main classes' interface
   //...
 private:
   Facade(IFactory& factory);

   static Facade* s_pFacade;
   IFactory& m_factory;
   // members to main classes' interface
   //...
};
} // namespace TheBest

#endif // THEBEST_FACADE_H
