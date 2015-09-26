#ifndef HELLO_WORD_SHADER_HH_
# define HELLO_WORD_SHADER_HH_

#include "slim/engine/Engine.hh"

class	HelloWorldShader : public slim::engine::Engine
{
public:
    HelloWorldShader();
    ~HelloWorldShader();

public:
    void    onInit() override;
};

#endif // !HELLO_WORD_SHADER_HH_
