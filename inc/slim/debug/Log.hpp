namespace slim
{
namespace debug
{

void
LogBase::setConsoleOutputLevel(char level)
{
    m_consoleOutputLevel = level;
    this->manageActivations();
}

void
LogBase::setFileOutputLevel(char level)
{
    m_fileOutputLevel = level;
    this->manageActivations();
}

}
}
