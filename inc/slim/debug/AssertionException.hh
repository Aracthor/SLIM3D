//
// AssertionException.hh for SLIM in /home/aracthor/programs/projects/SLIM/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:34:35 2015 Aracthor
// Last Update Mon Aug 31 23:39:40 2015 Aracthor
//

#ifndef SLIM_DEBUG_ASSERTION_EXCEPTION_HH_
# define SLIM_DEBUG_ASSERTION_EXCEPTION_HH_

# include "slim/debug/Exception.hh"

namespace slim
{
namespace debug
{

class	AssertionException : public Exception
{
public:
    AssertionException(const char* file, const char* function, int line);
    ~AssertionException() throw();
};

}
}

#endif // !SLIM_DEBUG_ASSERTION_EXCEPTION_HH_
