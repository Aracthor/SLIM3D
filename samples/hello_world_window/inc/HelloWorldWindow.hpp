#ifndef HELLO_WORLD_WINDOW_HPP_
# define HELLO_WORLD_WINDOW_HPP_

# include "slim/engine/Engine.hpp"

class	HelloWorldWindow : public slim::engine::Engine
{
public:
    HelloWorldWindow(int argc, char** argv);
    ~HelloWorldWindow();

public:
    void    onInit() override;
    void    onUpdate(slim::time::Clock::time elapsed) override;
};

#endif // !HELLO_WORLD_WINDOW_HPP_
