#include "slim/debug/WindowsException.hh"

#include <sysinfoapi.h>

namespace slim
{
namespace time
{

Clock::time
Clock::getCurrentTime() const
{
    Clock::time	ticks = GetTickCount64();

    if (ticks == 0)
    {
	debug::WindowsException::throws(__FILE__, __func__, __LINE__);
    }

    return ticks;
}

}
}
