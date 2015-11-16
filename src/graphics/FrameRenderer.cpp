#include "slim/graphics/FrameRenderer.hpp"

namespace slim
{
namespace graphics
{

FrameRenderer::FrameRenderer() :
    m_memory(memory::Manager::createChunk<memory::ArenaChunk>(SLIM_GRAPHICS_FRAME_RENDERER_MEMORY_SIZE, "frame renderer"))
{
}

FrameRenderer::~FrameRenderer()
{
}


void
FrameRenderer::reset()
{
    m_memory.clear();
}

// TODO other functions

}
}
