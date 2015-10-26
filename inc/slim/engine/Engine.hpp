#ifndef SLIM_ENGINE_ENGINE_HH_
# define SLIM_ENGINE_ENGINE_HH_

# include "slim/core/SingletonsManager.hpp"
# include "slim/engine/GameplayLoop.hpp"
# include "slim/engine/RenderLoop.hpp"
# include "slim/events/EventsLoop.hpp"
# include "slim/memory/ArenaChunk.hpp"
# include "slim/time/Synchronizer.hpp"
# include "slim/window/WindowImplementation.hpp"

# include "slim/memory/units.h"

# define SLIM_ENGINE_CORE_MEMORY_SIZE	(1 * SLIM_MEMORY_MEBIBYTE)

namespace slim
{
namespace engine
{

class	Engine
{
public:
    Engine(int argc, char** argv);
    virtual ~Engine();

public:
    void	start();
    inline void	stop();

public:
    inline unsigned int		getGameplayFramerate() const;
    inline unsigned int		getRenderFramerate() const;
    inline window::Window*	getCurrentWindow();

public:
    inline void		setGameplayFramerate(unsigned int framerate);
    inline void		setRenderFramerate(unsigned int framerate);

public:
    template <class Singleton>
    inline void		addModule();

protected:
    virtual void	onInit();
    virtual void	onUpdate(time::Clock::time elapsedTime);
    virtual void	onShutdown();

private:
    void        	parseCommandLine(int argc, char** argv);
    void		init();
    void		loop();
    inline bool		isRunning() const;
    void		update(time::Clock::time elapsedTime);
    void		render() const;
    void		shutdown();

protected:
    window::Window::Parameters	m_windowParameters;

private:
    core::SingletonsManager		m_singletonsManager;
    memory::ArenaChunk*			m_memory;
    time::Synchronizer			m_synchronizer;
    window::WindowImplementation*	m_window = nullptr;
    GameplayLoop			m_gameplayLoop;
    RenderLoop				m_renderLoop;
    bool				m_running;

    friend class	GameplayLoop;
    friend class	RenderLoop;
};

}
}

# include "Engine.ipp"

#endif // !SLIM_ENGINE_ENGINE_HH_
