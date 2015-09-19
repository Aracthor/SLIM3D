#include "slim/engine/Engine.hh"

class HelloWorldEngine : public slim::engine::Engine
{
public:
    HelloWorldEngine();
    ~HelloWorldEngine();

public:
    void    onInit() override;
};
