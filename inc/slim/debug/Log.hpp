namespace slim
{
namespace debug
{

void
LogBase::setConsoleOutputLevel(char level)
{
    m_consoleOutputLevel = level;
}

void
LogBase::setFileOutputLevel(char level)
{
    m_fileOutputLevel = level;
}

template <typename T>
void
LogBase::writeLog(const T& elem)
{
    this->write(elem, 0);
}

template <typename T>
void
LogBase::writeInfo(const T& elem)
{
    this->write(elem, 1);
}

template <typename T>
void
LogBase::writeWarning(const T& elem)
{
    this->write(elem, 2);
}

template <typename T>
void
LogBase::writeError(const T& elem)
{
    this->write(elem, 3);
}

void
LogBase::writeLog(const char* message)
{
    this->write(message, 0);
}

void
LogBase::writeInfo(const char* message)
{
    this->write(message, 1);
}

void
LogBase::writeWarning(const char* message)
{
    this->write(message, 2);
}

void
LogBase::writeError(const char* message)
{
    this->write(message, 3);
}


template <typename T>
void
LogBase::write(const T& object, unsigned int level)
{
    if (level >= m_consoleOutputLevel || level >= m_fileOutputLevel)
    {
	m_buffer << object;
	this->flush(level);
	m_buffer.clear();
    }
}

}
}
