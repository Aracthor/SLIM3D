#ifndef SLIM_GRAPHICS_FRAME_RENDERER_HPP_
# define SLIM_GRAPHICS_FRAME_RENDERER_HPP_

# include "slim/graphics/IFrameRenderer.hpp"
# include "slim/memory/ArenaChunk.hpp"
# include "slim/memory/units.h"
# include "slim/shader/Program.hpp"

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
    void	registerCamera(const camera::Camera* camera) override;
    void	addMesh(const mesh::Node& mesh) override;
    void	draw() override;

private:
    struct			MeshList
    {
	const mesh::Mesh*	mesh;
	MeshList*		next;
	const Matrix4x4*	matrix;
    };

    struct			ProgramsList
    {
	MeshList*		meshes;
	const shader::Program*	shader;
	ProgramsList*		next;
    };

private:
    ProgramsList*		createNewProgramList(const mesh::Node& mesh);
    MeshList*			createNewMeshList(const mesh::Node& mesh);

private:
    memory::ArenaChunk&		m_memory;
    ProgramsList*		m_list;
    const camera::Camera*	m_camera;
};

}
}

# include "FrameRenderer.ipp"

#endif // !SLIM_GRAPHICS_FRAME_RENDERER_HPP_
