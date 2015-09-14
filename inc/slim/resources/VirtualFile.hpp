namespace slim
{
namespace resources
{

unsigned int
VirtualFile::getSize() const
{
    return m_size;
}


template <typename T>
void
VirtualFile::readPureData(T& data)
{
    memcpy(&data, &m_data[m_index], sizeof(T));
    m_index += sizeof(T);
}

}
}
