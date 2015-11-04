#include "CloseListener.hpp"
#include "CursorImageEngine.hpp"

CursorImageEngine::CursorImageEngine(int argc, char** argv) :
    slim::engine::Engine(argc, argv)
{
    m_windowParameters.width = 800;
    m_windowParameters.height = 600;
    m_windowParameters.fullscreen = false;
    m_windowParameters.title = "SLIM3D samples - cursor image";
}

CursorImageEngine::~CursorImageEngine()
{
}


void
CursorImageEngine::onInit()
{
    m_image = slim::assets::Asset::create<slim::assets::Image>("cursor.png");
    m_cursor = new slim::window::Cursor(m_image);
    slim::assets::Manager::instance.loadNeededAssets();
    this->getCurrentWindow()->setCursor(m_cursor);

    this->getCurrentWindow()->getEventsManager().addCloseListener(new CloseListener(this));
}

void
CursorImageEngine::onShutdown()
{
    delete m_image;
    delete m_cursor;
}
