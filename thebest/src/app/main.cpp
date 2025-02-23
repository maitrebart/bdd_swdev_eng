#include "thebest/facade.h"
#include "factory.h"

int main(int argc, const char** argv)
{
	using namespace TheBest;
	Facade::create();
   
   int result(0);
	// create other main classes,
	// passing interface to factory
	// via facade
   //...
   
   return result;
}
