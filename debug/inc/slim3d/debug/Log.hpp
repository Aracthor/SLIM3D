//
// Log.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Tue Sep  1 23:20:48 2015 Aracthor
// Last Update Wed Sep  2 17:33:15 2015 Aracthor
//

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
