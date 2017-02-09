namespace slim
{
namespace graphics
{

void
Context::swapBuffers()
{
    eglSwapBuffers(m_display, m_surface);
}

}
}
