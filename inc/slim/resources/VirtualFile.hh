#ifndef SLIM_RESOURCES_VIRTUAL_FILE_HH_
# define SLIM_RESOURCES_VIRTUAL_FILE_HH_

# include "slim/resources/data.hh"

# define SLIM_RESOURCES_FILE_READ_BUFFER_SIZE	0x1000

namespace slim
{
namespace resources
{

class	VirtualFile
{
public:
    static VirtualFile*	fromRealFile(const char* fileName);

public:
    VirtualFile(byte* data, unsigned int size);
    VirtualFile(const VirtualFile& reference);
    virtual ~VirtualFile();

public:
    inline unsigned int	getSize() const;

public:
    template <typename T>
    void	readPureData(T& data);

private:
    byte*		m_data;
    unsigned int	m_size;
    unsigned int	m_index = 0;
};

}
}

# include "VirtualFile.hpp"

#endif // !SLIM_RESOURCES_VIRTUAL_FILE_HH_
