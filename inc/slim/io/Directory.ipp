template <class T>
T*
Directory::newFile(const char* fileName)
{
    char	completePath[SLIM_IO_MAX_PATH_LENGTH];

    strcpy(completePath, m_path);
    strncat(completePath, fileName, SLIM_IO_MAX_PATH_LENGTH - m_pathSize);

    return new T(completePath);
}

const char*
Directory::getPath() const
{
    return (m_path);
}
