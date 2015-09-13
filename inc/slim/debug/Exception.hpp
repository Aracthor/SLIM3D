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
