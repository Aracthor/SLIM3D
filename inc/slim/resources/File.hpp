namespace slim
{
namespace resources
{

const char*
File::getName() const
{
    return m_name;
}

FileInfos&
File::getInfos() const
{
    return m_infos;
}

}
}
