#ifndef SLIM_GRAPHICS_I_FRAME_RENDERER_HPP_
# define SLIM_GRAPHICS_I_FRAME_RENDERER_HPP_

# include "slim/camera/Camera.hpp"
# include "slim/mesh/Mesh.hpp"

namespace slim
{
namespace graphics
{

class	IFrameRenderer
{
public:
    virtual ~IFrameRenderer();

public:
    virtual void	reset() = 0;
    virtual void	registerCamera(const camera::Camera& camera) = 0;
    virtual void	addMesh(const mesh::Mesh& mesh) = 0;
    virtual void	draw() = 0;
};

}
}

#endif // !SLIM_GRAPHICS_I_FRAME_RENDERER_HPP_
