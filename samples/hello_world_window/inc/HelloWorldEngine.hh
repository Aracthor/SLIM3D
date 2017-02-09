#ifndef HELLO_WORLD_ENGINE_HH_
# define HELLO_WORLD_ENGINE_HH_

# include "slim/engine/Engine.hh"

class	HelloWorldEngine : public slim::engine::Engine
{
public:
    HelloWorldEngine(int argc, char** argv);
    ~HelloWorldEngine();

public:
    void    onInit() override;
};

#endif // !HELLO_WORLD_ENGINE_HH_