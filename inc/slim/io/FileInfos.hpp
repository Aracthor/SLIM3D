#ifndef SLIM_IO_FILE_INFOS_HPP_
# define SLIM_IO_FILE_INFOS_HPP_

# include <sys/stat.h>
# include <sys/types.h>

namespace slim
{
namespace io
{

class	FileInfos
{
public:
    FileInfos(const char* name);
    ~FileInfos();

public:
    unsigned int	getSize();

private:
    void	checkForInitialization();
    void	init();

private:
    const char*	m_name;
    struct stat	m_stats;
    bool	m_inited = false;
};

}
}

#endif // !SLIM_IO_FILE_INFOS_HPP_
