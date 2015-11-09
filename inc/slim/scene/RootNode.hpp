#ifndef SLIM_SCENE_ROOT_NODE_HPP_
# define SLIM_SCENE_ROOT_NODE_HPP_

# include "slim/scene/Node.hpp"

namespace slim
{
namespace scene
{

class	RootNode : public Node
{
public:
    RootNode(memory::Chunk& chunk);
    ~RootNode();

protected:
    void	updateData() override;
};

}
}

#endif // !SLIM_SCENE_ROOT_NODE_HPP_
