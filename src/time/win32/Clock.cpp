#include "slim/debug/WindowsException.hh"

#include <Windows.h>

namespace slim
{
namespace time
{

Clock::time
Clock::getCurrentTime() const
{
    LARGE_INTEGER 	time;
    LARGE_INTEGER	frequency;

    // TODO check if frequency can be stored.

    if (!QueryPerformanceCounter(&time) || !QueryPerformanceFrequency(&frequency))
    {
	debug::WindowsException::throws(__FILE__, __func__, __LINE__);
    }

    time.QuadPart *= 1000000;
    time.QuadPart /= frequency.QuadPart;

    return static_cast<Clock::time>(time.QuadPart);
}

}
}
