#include <unistd.h>

namespace slim
{
namespace debug
{

void
exitImplementation(int returnValue)
{
    ::_exit(returnValue);
}

}
}
