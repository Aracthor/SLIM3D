#ifndef HELLO_WORLD_SCENE_HH_
# define HELLO_WORLD_SCENE_HH_

# include "slim/engine/Engine.hpp"

class	HelloWorldScene : public slim::engine::Engine
{
public:
    HelloWorldScene(int argc, char** argv);
    ~HelloWorldScene();

public:
    void    onInit() override;
    void    onUpdate(slim::time::Clock::time elapsed) override;
};

#endif // !HELLO_WORLD_SCENE_HH_
