#include "slim/engine/Engine.hh"
#include "slim/window/Cursor.hh"

class	CursorImageEngine : public slim::engine::Engine
{
public:
    CursorImageEngine();
    ~CursorImageEngine();

public:
    void    onInit() override;
    void    onShutdown() override;

private:
    slim::assets::Image*	m_image;
    slim::window::Cursor*	m_cursor;
};
