#ifndef SLIM_SCENE_SCENE_HPP_
# define SLIM_SCENE_SCENE_HPP_

# include "slim/camera/Camera.hpp"
# include "slim/graphics/IFrameRenderer.hpp"
# include "slim/memory/Chunk.hpp"
# include "slim/memory/SmartStackChunk.hpp"
# include "slim/scene/RootNode.hpp"
# include "slim/time/Clock.hpp"

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
    void			update(time::Clock::time elapsedTime);
    void			display() const;

public:
    inline const char*		getName() const;
    inline const RootNode*	getRoot() const;
    inline RootNode*		getRoot();

private:
    typedef memory::SmartStackChunk	SceneChunk;

private:
    void			displayNode(const Node* node) const;

private:
    const char*	        m_name;
    memory::Chunk&	m_memory;
    RootNode*		m_root;
    camera::Camera*	m_activeCamera = nullptr;
    mutable graphics::IFrameRenderer*	m_frameRenderer;
};

}
}

# include "Scene.ipp"

#endif // !SLIM_SCENE_SCENE_HPP_
