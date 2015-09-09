//
// Log.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Tue Sep  1 23:20:48 2015 Aracthor
// Last Update Thu Sep 10 00:02:07 2015 Aracthor
//

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
    this->writeObject(elem, 0);
}

template <typename T>
void
LogBase::writeInfo(const T& elem)
{
    this->writeObject(elem, 1);
}

template <typename T>
void
LogBase::writeWarning(const T& elem)
{
    this->writeObject(elem, 2);
}

template <typename T>
void
LogBase::writeError(const T& elem)
{
    this->writeObject(elem, 3);
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
LogBase::writeObject(const T& object, unsigned int level)
{
    char	buffer[SLIM3D_DEBUG_ELEMENT_BUFFER_SIZE];

    m_dumper.dump(object, buffer, SLIM3D_DEBUG_ELEMENT_BUFFER_SIZE);
    this->write(buffer, level);
}

}
}
