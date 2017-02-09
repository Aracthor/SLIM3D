#ifndef SLIM_IO_WRITING_FILE_HPP_
# define SLIM_IO_WRITING_FILE_HPP_

# include "slim/io/File.hpp"

namespace slim
{
namespace io
{

class	WritingFile : public File
{
public:
    WritingFile(const char* name);
    virtual ~WritingFile();

public:
    virtual size_t	write(const void* data, size_t size) = 0;
};

}
}

#endif // !SLIM_IO_WRITING_FILE_HPP_
