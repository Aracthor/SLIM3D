//
// AssertionException.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:34:35 2015 Aracthor
// Last Update Mon Aug 31 23:39:40 2015 Aracthor
//

#ifndef SLIM3D_DEBUG_ASSERTION_EXCEPTION_HH_
# define SLIM3D_DEBUG_ASSERTION_EXCEPTION_HH_

# include "slim3d/debug/Exception.hh"

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

#endif // !SLIM3D_DEBUG_ASSERTION_EXCEPTION_HH_
