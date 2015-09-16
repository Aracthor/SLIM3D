#include "slim/debug/SyscallException.hh"

#include <Windows.h>

namespace slim
{
namespace time
{

Sleeper::Sleeper()
{
}

Sleeper::~Sleeper()
{
}

void
Sleeper::usleep(time_t microseconds)
{
    // TODO
}

void
Sleeper::sleep(time_t seconds)
{
    // TODO
}

}
}
