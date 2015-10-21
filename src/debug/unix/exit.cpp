#include <unistd.h>

namespace slim
{
namespace debug
{

void
exit::exitImplementation(int returnValue)
{
    ::_exit(returnValue);
}

}
}
