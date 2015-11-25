#include "slim/mesh/Mesh.hpp"
#include "slim/io/VirtualFile.hpp"

namespace slim
{
namespace mesh
{

const char* const
Mesh::typeName = "mesh";

void
Mesh::initLoader(memory::Chunk& memory)
{
    s_loader = memory.create<Loader>();
}

void
Mesh::destroyLoader(memory::Chunk& memory)
{
    memory.destroy(s_loader);
}


Loader*
Mesh::s_loader = nullptr;


Mesh::Mesh(const char* name) :
    assets::SingleFileAsset(Mesh::typeName, name, name)
{
}

Mesh::~Mesh()
{
}


void
Mesh::draw() const
{
    m_vao.bind();
    {
	if (m_vao.useIndices())
	{
	    glDrawElements(m_renderMode, m_vao.getSize(), sizeof(Index), nullptr);
	}
	else
	{
	    glDrawArrays(m_renderMode, 0, m_vao.getSize());
	}
    }
    m_vao.unbind();
}


bool
Mesh::loadFromFile(const char* const path)
{
    io::VirtualFile	file = io::VirtualFile::fromRealFile(path);
    FileLoader::Data	data;

    if (s_loader->loadFile(file, data) == false)
    {
	return false;
    }

    m_renderMode = triangles;
    m_vao = s_loader->generateVAO(data);
    // TODO

    return true;
}

void
Mesh::unloadData()
{
    m_vao.~VertexArrayObject();
}

}
}
