#ifndef SLIM_CORE_FILE_ACCESSER_HPP_
# define SLIM_CORE_FILE_ACCESSER_HPP_

# include "slim/containers/Buffer.hpp"

# define SLIM_CORE_MAX_PATH_SIZE	0x200

namespace slim
{
namespace core
{

class	FileAccesser
{
public:
    FileAccesser(const char* folder);
    virtual ~FileAccesser();

public:
    inline void	setExecutablePath(const char* path);

protected:
    containers::Buffer<char, SLIM_CORE_MAX_PATH_SIZE>	m_path;

private:
    const char*	m_folder;
};

}
}

# include "FileAccesser.ipp"

#endif // !SLIM_CORE_FILE_ACCESSER_HPP_
