#ifndef SLIM_SCENE_NODE_HPP_
# define SLIM_SCENE_NODE_HPP_

# include "slim/scene/Node.hpp"

namespace slim
{
namespace scene
{

class	Node
{
public:
    virtual ~Node();

public:
    inline const char*	getName() const;

protected:
    Node(const char* name, Node* parent);

private:
    const char*	m_name;
    Node*	m_parent;
};

}
}

# include "Node.ipp"

#endif // !SLIM_SCENE_NODE_HPP_
