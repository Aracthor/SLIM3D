//
// File.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
// 
// Made by Aracthor
// 
// Started on  Wed Sep  2 14:14:36 2015 Aracthor
// Last Update Thu Sep  3 21:46:36 2015 Aracthor
//

#ifndef SLIMD_RESOURCES_FILE_HH_
# define SLIMD_RESOURCES_FILE_HH_

# include "slim3d/resources/FileException.hh"

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
