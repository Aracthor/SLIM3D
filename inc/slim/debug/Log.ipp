namespace slim
{
namespace debug
{

void
Log::setConsoleOutputLevel(char level)
{
    m_consoleOutputLevel = level;
    this->manageActivations();
}

void
Log::setFileOutputLevel(char level)
{
    m_fileOutputLevel = level;
    this->manageActivations();
}

}
}
