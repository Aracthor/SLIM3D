namespace slim
{
namespace scene
{

const char*
Node::getName() const
{
    return m_name;
}

const containers::List<Node>&
Node::getChildren() const
{
    return m_children;
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
