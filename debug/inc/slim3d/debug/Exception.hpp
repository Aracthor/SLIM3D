//
// Exception.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 18:22:37 2015 Aracthor
// Last Update Mon Aug 31 18:25:55 2015 Aracthor
//

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
