#ifndef SLIM_MESH_NODE_HPP_
# define SLIM_MESH_NODE_HPP_

# include "slim/mesh/Mesh.hpp"
# include "slim/scene/Node.hpp"

namespace slim
{
namespace mesh
{

class	Node : public scene::Node
{
public:
    Node(memory::Chunk& memory, const char* name, scene::Node* parent, Mesh* mesh);
    ~Node();

public:
    inline const Mesh*	getMesh() const;
    inline Mesh*	getMesh();

public:
    void	updateData(time::Clock::time elapsedTime) override;

private:
    Mesh*	m_mesh;
};

}
}

# include "Node.ipp"

#endif // !SLIM_MESH_NODE_HPP_
