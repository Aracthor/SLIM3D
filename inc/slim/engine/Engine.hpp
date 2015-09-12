//
// Engine.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 15:04:21 2015 Aracthor
// Last Update Sat Sep 12 18:19:08 2015 Aracthor
//

namespace slim
{
namespace engine
{

unsigned int
Engine::getGameplayFramerate() const
{
    return m_gameplayLoop.getFramerate();
}

unsigned int
Engine::getRenderFramerate() const
{
    return m_renderLoop.getFramerate();
}


void
Engine::setGameplayFramerate(unsigned int framerate)
{
    m_gameplayLoop.setFramerate(framerate);
}

void
Engine::setRenderFramerate(unsigned int framerate)
{
    m_renderLoop.setFramerate(framerate);
}

}
}
