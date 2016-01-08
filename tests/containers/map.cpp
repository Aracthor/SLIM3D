#include <iostream>

#include "slim/containers/Map.hpp"
#include "slim/memory/ArenaChunk.hpp"
#include "slim/memory/Manager.hpp"

#include <cstring>

using namespace slim;

static int	test(int (function)(), const char* name)
{
    int		return_value = !function();

    if (return_value != 0)
    {
	std::cerr << "TEST FAIL: " << name << std::endl;
    }

    return return_value;
}

static int				classic_map()
{
    memory::Chunk&      chunk = memory::Manager::instance.createChunk<memory::ArenaChunk>(0x1000, "classic map");
    containers::Map<int, const char*>	map(chunk);

    map.insert(42, "forty two");
    map.insert(-1, "minus one");
    map.insert(0, "zero");
    map.insert(1337, "one thousand three hundred and thirsty seven");

    return (strcmp(map[42], "forty two") == 0 &&
	    strcmp(map[-1], "minus one") == 0 &&
	    strcmp(map[1337], "one thousand three hundred and thirsty seven") == 0 &&
	    strcmp(map[0], "zero") == 0);
}

int	main()
{
    int	return_value;

    memory::Manager::instance.init();

    return_value = (test(classic_map, "classic map") == 0);

    memory::Manager::instance.destroy();

    return return_value;
}
