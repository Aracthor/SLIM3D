//
// Exception.hpp for SLIM in /home/aracthor/programs/projects/SLIM/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 18:22:37 2015 Aracthor
// Last Update Thu Sep 10 00:03:01 2015 Aracthor
//

namespace slim
{
namespace debug
{

const char*
Exception::getProblem() const throw()
{
    return (m_problem);
}

const char*
Exception::getFile() const throw()
{
    return (m_file);
}

const char*
Exception::getFunction() const throw()
{
    return (m_function);
}

int
Exception::getLine() const throw()
{
    return (m_line);
}

}
}
