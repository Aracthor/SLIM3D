namespace slim
{
namespace context
{

const ContextImplementation*
Context::getImplementation() const
{
    return m_implementation;
}

ContextImplementation*
Context::getImplementation()
{
    return m_implementation;
}

}
}
