namespace slim
{
namespace shader
{

void
Program::use() const
{
    glUseProgram(m_id);
}

}
}
