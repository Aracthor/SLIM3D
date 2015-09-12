//
// Directory.hpp for SLIM in /home/aracthor/programs/projects/SLIM/resources
// 
// Made by Aracthor
// 
// Started on  Thu Sep  3 21:54:04 2015 Aracthor
// Last Update Thu Sep  3 21:55:56 2015 Aracthor
//

template <class T>
T*
Directory::newFile(const char* fileName)
{
    char	completePath[SLIM_RESOURCES_MAX_PATH_LENGTH];

    strcpy(completePath, m_path);
    strncat(completePath, fileName, SLIM_RESOURCES_MAX_PATH_LENGTH - m_pathSize);

    return new T(completePath);
}

const char*
Directory::getPath() const
{
    return (m_path);
}
