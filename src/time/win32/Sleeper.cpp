#include "slim/debug/WindowsException.hpp"

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
    HANDLE		timer;
    LARGE_INTEGER	ft;

    ft.QuadPart = -(10 * microseconds); // Convert to 100 nanosecond interval, negative value indicates relative time

    SLIM_DEBUG_WINDOWS_SYSCALL_CALL_PTR(timer = CreateWaitableTimer(nullptr, TRUE, nullptr));
    SLIM_DEBUG_WINDOWS_SYSCALL_CALL(SetWaitableTimer(timer, &ft, 0, nullptr, nullptr, 0));
    if (WaitForSingleObject(timer, INFINITE) == WAIT_FAILED)
    {
	debug::WindowsException::throws(__FILE__, __func__, __LINE__);
    }
    SLIM_DEBUG_WINDOWS_SYSCALL_CALL(CloseHandle(timer));
}

void
Sleeper::sleep(time_t seconds)
{
    this->usleep(seconds * 1000000);
}

}
}
