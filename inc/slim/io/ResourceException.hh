#ifndef SLIM_IO_RESOURCE_EXCEPTION_HH_
# define SLIM_IO_RESOURCE_EXCEPTION_HH_

# include "slim/debug/Exception.hh"

namespace slim
{
namespace io
{

class	ResourceException : public debug::Exception
{
public:
    ResourceException(const char* resourceName, const char* message,
		      const char* file, const char* function, int line);
    virtual ~ResourceException() throw();

public:
    inline const char*	getResourcename() const;

protected:
    const char*	m_resourceName;
};

}
}

# include "ResourceException.hpp"

#endif // !SLIM_IO_RESOURCE_EXCEPTION_HH_
