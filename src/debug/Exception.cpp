#include "slim/debug/Exception.hh"

#include <cstdio>
#include <cstring>

namespace slim
{
namespace debug
{

Exception::Exception(const char* problem, const char* file, const char* function, int line) :
    m_problem(problem),
    m_file(file),
    m_function(function),
    m_line(line)
{
#ifdef _DEBUG
    snprintf(m_whatMessage, SLIM_DEBUG_MESSAGE_BUFFER_SIZE,
	     "file %s:\nfunction %s:\nline %d:\n%s",
	     file, function, line, problem);
#else
    strcpy(m_whatMessage, problem);
#endif
}

Exception::~Exception()
{
}


const char*
Exception::what() const throw()
{
    return (m_whatMessage);
}

}
}
