#include "slim/resources/IWritingFile.hh"

#define SLIM_DEBUG_CONSOLE_LOG_BUFFER_SIZE	0x1000

namespace slim
{
namespace debug
{

class		Log : public LogBase
{
public:
    Log(const char* name);
    ~Log();

public:
    void	init(resources::Directory& directory) override;
    void	destroy() override;

protected:
    void	write(const char* line, unsigned int size) override;

private:
    resources::IWritingFile*	m_file;
    char			m_fileBuffer[SLIM_DEBUG_CONSOLE_LOG_BUFFER_SIZE];
};

}
}
