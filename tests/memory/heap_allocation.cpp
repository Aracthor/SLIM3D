#include "slim/memory/Manager.hh"
#include "slim/memory/ArenaChunk.hh"
#include "slim/memory/StackChunk.hh"
#include "slim/time/Clock.hh"

#include <iostream>
#include <typeinfo>

#define TESTS_NUMBER	1000000

struct	Toto
{
    unsigned int	x;
    unsigned int	y;
    unsigned int	z;
};


void
malloc_test()
{
    slim::time::Clock   clock;
    int			i;
    Toto*		toto[TESTS_NUMBER];

    clock.reset();
    {
	for (i = 0; i < TESTS_NUMBER; i++)
	{
	    toto[i] = (Toto*)malloc(sizeof(Toto));
	}
	for (i = TESTS_NUMBER - 1; i >= 0; i--)
	{
	    free(toto[i]);
	}
    }
    clock.update();
    std::cout << "Elpased time for standard malloc:\t\t\t\t" << clock.getElapsedTime() << std::endl;
}

void
StackAllocator_test()
{
    slim::memory::Manager::instance.init();

    slim::memory::Chunk&	chunk = slim::memory::Manager::instance.createChunk<slim::memory::StackChunk>(100000000);
    slim::time::Clock		clock;
    int				i;
    Toto*			toto[TESTS_NUMBER];

    clock.reset();
    {
	for (i = 0; i < TESTS_NUMBER; i++)
	{
	    toto[i] = (Toto*)chunk.alloc(sizeof(toto[i]));
	}
	for (i = TESTS_NUMBER - 1; i >= 0; i--)
	{
	    chunk.free((char*)toto[i]);
	}
    }
    chunk.clear();
    clock.update();
    std::cout << "Elpased time for Memory chunk " << typeid(chunk).name() << ":\t" << clock.getElapsedTime() << std::endl;
}

int
main()
{
    malloc_test();
    StackAllocator_test();

    return 0;
}
