#ifndef SLIMD_IO_FILE_HPP_
# define SLIMD_IO_FILE_HPP_

# include "slim/io/FileInfos.hpp"

namespace slim
{
namespace io
{

class	File
{
public:
    File(const char* name);
    virtual ~File();

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

# include "File.ipp"

#endif // !SLIMD_IO_FILE_HPP_
