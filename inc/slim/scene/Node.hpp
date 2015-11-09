#ifndef SLIM_SCENE_NODE_HPP_
# define SLIM_SCENE_NODE_HPP_

# include "slim/containers/List.hpp"
# include "slim/memory/Chunk.hpp"
# include "slim/scene/Node.hpp"
# include "slim/scene/Transformable.hpp"

namespace slim
{
namespace scene
{

class	Node : public Transformable
{
public:
    virtual ~Node();

public:
    inline const char*	getName() const;

public:
    void		update();

protected:
    Node(memory::Chunk& chunk, const char* name, Node* parent);

protected:
    void		updateMatrix();
    virtual void        updateData() = 0;

private:
    const char*			m_name;
    Node*			m_parent;
    containers::List<Node>	m_children;
};

}
}

# include "Node.ipp"

#endif // !SLIM_SCENE_NODE_HPP_
