#include "slim/engine/Engine.hh"

class CloseListener : public slim::events::ICloseListener
{
public:
    CloseListener(slim::engine::Engine* engine) :
	m_engine(engine)
    {
    }

public:
    void onEvent() override
    {
	m_engine->stop();
    }

private:
    slim::engine::Engine*   m_engine;
};

class Test : public slim::engine::Engine
{
public:
    Test();
    ~Test();

    void	onInit() override;
};

Test::Test()
{
}

Test::~Test()
{
}

void
Test::onInit()
{
    this->getCurrentWindow()->getEventsManager().addCloseListener(new CloseListener(this));
}

int	main()
{
    Test test;

    test.start();

    return 0;
}