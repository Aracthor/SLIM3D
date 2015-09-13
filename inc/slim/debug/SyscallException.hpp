namespace slim
{
namespace debug
{

int
SyscallException::getErrnoCode() const
{
    return (m_errno);
}

}
}
