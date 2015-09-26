#ifndef CURSOR_IMAGE_ENGINE_HH_
# define CURSOR_IMAGE_ENGINE_HH_

# include "slim/engine/Engine.hh"
# include "slim/window/Cursor.hh"

class	CursorImageEngine : public slim::engine::Engine
{
public:
    CursorImageEngine(int argc, char** argv);
    ~CursorImageEngine();

public:
    void    onInit() override;
    void    onShutdown() override;

private:
    slim::assets::Image*	m_image;
    slim::window::Cursor*	m_cursor;
};

#endif // !CURSOR_IMAGE_ENGINE_HH_
