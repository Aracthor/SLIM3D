#ifndef SLIM_IO_VIRTUAL_FILE_HPP_
# define SLIM_IO_VIRTUAL_FILE_HPP_

# include "slim/containers/SingleWrap.hpp"
# include "slim/io/ReadingFile.hpp"
# include "slim/memory/ArenaChunk.hpp"

# include "slim/memory/units.h"

# define SLIM_IO_FILE_READ_BUFFER_SIZE	0x1000
# define SLIM_IO_UNKNOWN_FILE_NAME	"UNKNOWN_FILE"
# define SLIM_IO_VIRTUAL_FILE_MAX_SIZE	(10 * SLIM_MEMORY_MEBIBYTE)

namespace slim
{
namespace io
{

class	VirtualFile
{
public:
    static VirtualFile	fromRealFile(const char* fileName);
    static VirtualFile	fromRealFile(ReadingFile& file);

private:
    static memory::ArenaChunk&	getMemoryChunk();

private:
    static containers::SingleWrap<memory::ArenaChunk>	s_memory;
    

public:
    VirtualFile(unsigned char* data, unsigned int size, const char* name = SLIM_IO_UNKNOWN_FILE_NAME);
    VirtualFile(const VirtualFile& reference);
    virtual ~VirtualFile();

public:
    void	toBuffer(char* buffer, unsigned int size) const;

public:
    template <typename T>
    void		readPureData(T& data);
    void		read(unsigned char* buffer, unsigned int size);

public:
    const char*		getExtention() const;

public:
    inline unsigned int	getSize() const;
    inline const char*	getName() const;

private:
    unsigned char*	m_data;
    unsigned int	m_size;
    unsigned int	m_index = 0;
    const char*		m_name;
};

}
}

# include "VirtualFile.ipp"

#endif // !SLIM_IO_VIRTUAL_FILE_HPP_
