//
// ConsoleLog.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Tue Sep  1 23:36:18 2015 Aracthor
// Last Update Wed Sep  9 13:47:40 2015 Aracthor
//

#include "slim3d/resources/IWritingFile.hh"

#define SLIM3D_DEBUG_CONSOLE_LOG_BUFFER_SIZE	0x1000

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
    char			m_buffer[SLIM3D_DEBUG_CONSOLE_LOG_BUFFER_SIZE];
};

}
}
