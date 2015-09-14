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
