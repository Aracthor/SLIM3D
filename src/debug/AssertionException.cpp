//
// AssertionException.cpp for SLIM in /home/aracthor/programs/projects/SLIM/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:34:31 2015 Aracthor
// Last Update Mon Aug 31 23:39:44 2015 Aracthor
//

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
