#ifndef SLIM_SCENE_MANAGER_HPP_
# define SLIM_SCENE_MANAGER_HPP_

# include "slim/scene/Scene.hpp"

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
    inline const Scene*	getCurrentScene() const;
    inline Scene*	getCurrentScene();

public:
    inline void		setCurrentScene(Scene* scene);

private:
    Scene*		m_currentScene = nullptr;
};

}
}

# include "Manager.ipp"

#endif // !SLIM_SCENE_MANAGER_HPP_
