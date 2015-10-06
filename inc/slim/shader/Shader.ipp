namespace slim
{
namespace shader
{

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
