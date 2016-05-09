#ifndef CUBE_HPP_
# define CUBE_HPP_

# include "slim/engine/Engine.hpp"

class	Cube : public slim::engine::Engine
{
public:
    Cube(int argc, char** argv);
    ~Cube();

public:
    void    onInit() override;
    void    onUpdate(slim::time::Clock::time elapsed) override;
};

#endif // !CUBE_HPP_
