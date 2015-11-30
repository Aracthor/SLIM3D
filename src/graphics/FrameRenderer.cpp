#include "slim/graphics/FrameRenderer.hpp"
#include "slim/memory/Manager.hpp"

namespace slim
{
namespace graphics
{

FrameRenderer::FrameRenderer() :
    m_memory(memory::Manager::instance.createChunk<memory::ArenaChunk>(SLIM_GRAPHICS_FRAME_RENDERER_MEMORY_SIZE, "frame renderer"))
{
}

FrameRenderer::~FrameRenderer()
{
}


void
FrameRenderer::reset()
{
    m_memory.clear();
    m_list = nullptr;
    m_camera = nullptr;
}

void
FrameRenderer::registerCamera(const camera::Camera* camera)
{
    m_camera = camera;
}

void
FrameRenderer::addMesh(const mesh::Node& node)
{
    struct ProgramsList*	list = m_list;

    if (m_list == nullptr)
    {
	m_list = this->createNewProgramList(node);
    }
    else
    {
	while (list->shader != node.getMesh()->getMaterial()->getShader() && list->next != nullptr)
	{
	    list = list->next;
	}
	if (list->next == nullptr)
	{
	    list->next = this->createNewProgramList(node);
	}
	else
	{
	    MeshList*	meshes = list->meshes;

	    while (meshes->next != nullptr)
	    {
		meshes = meshes->next;
	    }
	    meshes->next = this->createNewMeshList(node);
	}
    }
}

void
FrameRenderer::draw()
{
    ProgramsList*	list;
    MeshList*		meshes;

    for (list = m_list; list != nullptr; list = list->next)
    {
	list->shader->use();
	for (meshes = list->meshes; meshes != nullptr; meshes = meshes->next)
	{
	    // TODO give shader transformation matrix uniform
	    meshes->mesh->draw();
	}
    }
}


FrameRenderer::ProgramsList*
FrameRenderer::createNewProgramList(const mesh::Node& node)
{
    ProgramsList*	list = m_memory.create<ProgramsList>();

    list->meshes = this->createNewMeshList(node);
    list->next = nullptr;
    list->shader = node.getMesh()->getMaterial()->getShader();

    return list;
}

FrameRenderer::MeshList*
FrameRenderer::createNewMeshList(const mesh::Node& node)
{
    MeshList*	list = m_memory.create<MeshList>();

    list->mesh = node.getMesh();
    list->next = nullptr;
    list->matrix = &node.getTransformationMatrix();

    return list;
}

// TODO other functions

}
}
