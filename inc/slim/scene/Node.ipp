namespace slim
{
namespace scene
{

const char*
Node::getName() const
{
    return m_name;
}


template <class NODE, typename ...Args>
NODE*
Node::addChild(const char* name, Args&& ...args)
{
    NODE*	node = m_memory.create<NODE>(m_memory, name, this, args...);

    m_children.pushBack(node);

    return node;
}

}
}
