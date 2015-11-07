#include <iostream>

#include "slim/memory/Manager.hpp"
#include "slim/memory/SmartStackChunk.hpp"

using namespace slim::memory;

int	smart_stack_test()
{
    Chunk&	chunk = Manager::instance.createChunk<SmartStackChunk>(10000, "test");
    void*	ptr1;
    void*	ptr2;
    void*	ptr3;

    ptr1 = chunk.alloc(500);
    ptr2 = chunk.alloc(1000);
    chunk.free(ptr2);
    ptr3 = chunk.alloc(5000);
    chunk.free(ptr1);
    ptr2 = chunk.alloc(4200);
    chunk.free(ptr2);
    chunk.free(ptr3);

    return 0;
}

int	main()
{
    int	return_value;
    
    Manager::instance.init();

    return_value = (smart_stack_test() == 0);

    Manager::instance.destroy();

    return return_value;
}
