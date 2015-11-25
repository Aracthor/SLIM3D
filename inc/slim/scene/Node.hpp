#ifndef SLIM_SCENE_NODE_HPP_
# define SLIM_SCENE_NODE_HPP_

# include "slim/containers/List.hpp"
# include "slim/memory/Chunk.hpp"
# include "slim/scene/Node.hpp"
# include "slim/scene/Transformable.hpp"
# include "slim/time/Clock.hpp"

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
    void		update(time::Clock::time elapsedTime);
    void		setAssetsNeeded();
    virtual void	setNodeAssetNeeded();

public:
    template <class NODE, typename ...Args> // NODE must inherit from slim::scene::Node, and cannot be RootNode.
    NODE*		addChild(const char* name, Args&& ...args);

protected:
    Node(memory::Chunk& chunk, const char* name, Node* parent);

protected:
    void		updateMatrix();
    virtual void	updateData(time::Clock::time elapsedTime) = 0;

protected:
    memory::Chunk&		m_memory;

private:
    const char*			m_name;
    Node*			m_parent;
    containers::List<Node>	m_children;
};

}
}

# include "Node.ipp"

#endif // !SLIM_SCENE_NODE_HPP_
