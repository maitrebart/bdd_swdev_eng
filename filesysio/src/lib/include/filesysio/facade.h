#ifndef FILESYSIO_FACADE_H
#define FILESYSIO_FACADE_H

namespace FileSysIo
{

class IFactory;

class Facade
{
public:
	static void create(); // uses default factory
	static void create(IFactory& factory); // for ext app or tst
	static Facade& instance();

	IFactory& factory();

private:
	Facade(IFactory& factory);
	
	static Facade* s_pFacade;
	IFactory& m_factory;
};
} // namespace FileSysIo

#endif // FILESYSIO_FACADE_H
