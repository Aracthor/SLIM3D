//
// ConsoleLog.hh for SLIM in /home/aracthor/programs/projects/SLIM/debug
// 
// Made by Aracthor
// 
// Started on  Tue Sep  1 23:36:18 2015 Aracthor
// Last Update Wed Sep  9 13:47:40 2015 Aracthor
//

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
    void	write(const char* message, unsigned int level) override;

private:
    resources::IWritingFile*	m_file;
    char			m_buffer[SLIM_DEBUG_CONSOLE_LOG_BUFFER_SIZE];
};

}
}
