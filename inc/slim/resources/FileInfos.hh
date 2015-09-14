#ifndef SLIM_RESOURCES_FILE_INFOS_HH_
# define SLIM_RESOURCES_FILE_INFOS_HH_

# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

namespace slim
{
namespace resources
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

#endif // !SLIM_RESOURCES_FILE_INFOS_HH_
