namespace slim
{
namespace shader
{

const char*
Shader::getName() const
{
    return m_name;
}

Shader::EType
Shader::getType() const
{
    return m_type;
}

GLuint
Shader::getId() const
{
    return m_id;
}

}
}
