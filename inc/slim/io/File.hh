#ifndef SLIMD_IO_FILE_HH_
# define SLIMD_IO_FILE_HH_

# include "slim/io/FileInfos.hh"

namespace slim
{
namespace io
{

class	File
{
public:
    File(const char* name);
    virtual ~File() noexcept(false);

public:
    inline FileInfos&	getInfos() const;

public:
    inline const char*	getName() const;

protected:
    void		onError(const char* message) const;

protected:
    const char*		m_name;

private:
    mutable FileInfos	m_infos;
};

}
}

# include "File.hpp"

#endif // !SLIMD_IO_FILE_HH_
