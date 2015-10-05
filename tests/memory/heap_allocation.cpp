#include "slim/memory/Manager.hh"
#include "slim/memory/Allocatable.hh"
#include "slim/time/Clock.hh"

#include <iostream>

#define TESTS_NUMBER	1000000

struct	Toto : public slim::memory::Allocatable<Toto>
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
    std::cout << "Elpased time for standard malloc:\t" << clock.getElapsedTime() << std::endl;
}

void
StackAllocator_test()
{
    slim::memory::Manager::instance.onInit();

    slim::time::Clock   clock;
    int			i;
    Toto*		toto[TESTS_NUMBER];

    clock.reset();
    {
	for (i = 0; i < TESTS_NUMBER; i++)
	{
	    toto[i] = new Toto();
	}
	for (i = TESTS_NUMBER - 1; i >= 0; i--)
	{
	    delete toto[i];
	}
    }
    clock.update();
    std::cout << "Elpased time for StackAllocator:\t" << clock.getElapsedTime() << std::endl;
}

int
main()
{
    malloc_test();
    StackAllocator_test();

    return 0;
}
