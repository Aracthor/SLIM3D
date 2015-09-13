#ifndef SLIMD_RESOURCES_FILE_HH_
# define SLIMD_RESOURCES_FILE_HH_

# include "slim/resources/FileException.hh"

namespace slim
{
namespace resources
{

class	File
{
public:
    File(const char* name);
    virtual ~File();

public:
    inline const char*	getName() const;

protected:
    void	onError(const char* message) const;

protected:
    const char*	m_name;
};

# include "File.hpp"

}
}

#endif // !SLIMD_RESOURCES_FILE_HH_
