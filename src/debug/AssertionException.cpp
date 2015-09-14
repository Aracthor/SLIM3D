#include "slim/debug/AssertionException.hh"

namespace slim
{
namespace debug
{

AssertionException::AssertionException(const char* file, const char* function, int line) :
    Exception("Assertion alert", file, function, line)
{
}

AssertionException::~AssertionException() throw()
{
}

}
}
