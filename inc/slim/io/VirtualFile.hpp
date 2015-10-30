#ifndef SLIM_IO_VIRTUAL_FILE_HPP_
# define SLIM_IO_VIRTUAL_FILE_HPP_

# include "slim/io/ReadingFile.hpp"

# define SLIM_IO_FILE_READ_BUFFER_SIZE	0x1000

namespace slim
{
namespace io
{

class	VirtualFile
{
public:
    static VirtualFile	fromRealFile(const char* fileName);
    static VirtualFile	fromRealFile(ReadingFile& file);

public:
    VirtualFile(unsigned char* data, unsigned int size);
    VirtualFile(const VirtualFile& reference);
    virtual ~VirtualFile();

public:
    void	toBuffer(char* buffer, unsigned int size) const;

public:
    template <typename T>
    void		readPureData(T& data);
    void		read(unsigned char* buffer, unsigned int size);

public:
    inline unsigned int	getSize() const;

private:
    unsigned char*	m_data;
    unsigned int	m_size;
    unsigned int	m_index = 0;
};

}
}

# include "VirtualFile.ipp"

#endif // !SLIM_IO_VIRTUAL_FILE_HPP_
