#ifndef SLIM_GRAPHICS_FRAME_RENDERER_HPP_
# define SLIM_GRAPHICS_FRAME_RENDERER_HPP_

# include "slim/graphics/IFrameRenderer.hpp"
# include "slim/memory/ArenaChunk.hpp"
# include "slim/memory/units.h"

# define SLIM_GRAPHICS_FRAME_RENDERER_MEMORY_SIZE	(1 * SLIM_MEMORY_MEBIBYTE)

namespace slim
{
namespace graphics
{

class	FrameRenderer : public IFrameRenderer
{
public:
    FrameRenderer();
    ~FrameRenderer();

public:
    void	reset() override;
    void	registerCamera(const camera::Camera& camera) override;
    void	addMesh(const mesh::Mesh& mesh) override;
    void	draw() override;

private:
    memory::ArenaChunk	m_memory;
};

}
}

# include "FrameRenderer.ipp"

#endif // !SLIM_GRAPHICS_FRAME_RENDERER_HPP_
