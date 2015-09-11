//
// Exception.cpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 18:23:43 2015 Aracthor
// Last Update Mon Aug 31 18:33:10 2015 Aracthor
//

#include "slim3d/debug/Exception.hh"

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
    snprintf(m_whatMessage, SLIM3D_DEBUG_MESSAGE_BUFFER_SIZE,
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
