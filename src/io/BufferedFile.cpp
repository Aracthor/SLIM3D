#include "slim/debug/exit.hpp"
#include "slim/io/BufferedFile.hpp"

namespace slim
{
namespace io
{

BufferedFile::BufferedFile()
{
}

BufferedFile::~BufferedFile()
{
    if (fclose(m_stream) != 0)
    {
	SLIM_DEBUG_EXIT("Cannot close buffered file.");
    }
}

}
}
