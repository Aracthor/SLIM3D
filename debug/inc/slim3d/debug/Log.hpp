//
// Log.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Tue Sep  1 23:20:48 2015 Aracthor
// Last Update Tue Sep  1 23:27:43 2015 Aracthor
//

void
Log::setConsoleOutputLevel(char level)
{
    m_consoleOutputLevel = level;
}

void
Log::setFileOutputLevel(char level)
{
    m_fileOutputLevel = level;
}

template <typename T>
void
Log::writeLog(const T& elem)
{
    this->write(elem, 0);
}

template <typename T>
void
Log::writeInfo(const T& elem)
{
    this->write(elem, 1);
}

template <typename T>
void
Log::writeWarning(const T& elem)
{
    this->write(elem, 2);
}

template <typename T>
void
Log::writeError(const T& elem)
{
    this->write(elem, 3);
}
