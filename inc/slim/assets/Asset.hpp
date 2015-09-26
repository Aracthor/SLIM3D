namespace slim
{
namespace assets
{

const char*
Asset::getType() const
{
    return m_type;
}

const char*
Asset::getName() const
{
    return m_name;
}

bool
Asset::isNeeded() const
{
    return m_needed;
}

bool
Asset::isLoaded() const
{
    return m_loaded;
}

}
}
