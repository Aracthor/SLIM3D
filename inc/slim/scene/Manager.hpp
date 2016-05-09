#ifndef SLIM_SCENE_MANAGER_HPP_
# define SLIM_SCENE_MANAGER_HPP_

# include "slim/containers/PresizedPool.hpp"
# include "slim/scene/Scene.hpp"

# define SLIM_SCENE_MAX_NUMBER	10

namespace slim
{
namespace scene
{

class	Manager
{
public:
    Manager();
    ~Manager();

public:
    inline Scene*	createBlankScene(const char* name);
    inline void		deleteScene(Scene* scene);
    inline void		deleteAllScenes();

public:
    inline const Scene*	getCurrentScene() const;
    inline Scene*	getCurrentScene();

public:
    void		setCurrentScene(Scene* scene);

private:
    Scene*	        m_currentScene = nullptr;
    containers::PresizedPool<Scene, SLIM_SCENE_MAX_NUMBER>	m_scenes;
};

}
}

# include "Manager.ipp"

#endif // !SLIM_SCENE_MANAGER_HPP_
