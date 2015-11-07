#ifndef SLIM_SCENE_SCENE_HPP_
# define SLIM_SCENE_SCENE_HPP_

# include "slim/memory/Chunk.hpp"
# include "slim/memory/SmartStackChunk.hpp"
# include "slim/scene/RootNode.hpp"

# include "slim/memory/units.h"

# define SLIM_SCENE_MEMORY_SIZE	(100 * SLIM_MEMORY_KIBIBYTE)

namespace slim
{
namespace scene
{

class	Scene
{
public:
    Scene(const char* name);
    ~Scene();

public:
    inline const char*	getName() const;

private:
    typedef memory::SmartStackChunk	SceneChunk;

private:
    const char*	        m_name;
    memory::Chunk&	m_memory;
    RootNode*		m_root;
};

}
}

# include "Scene.ipp"

#endif // !SLIM_SCENE_SCENE_HPP_
