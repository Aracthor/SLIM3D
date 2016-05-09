#include "slim/graphics/glDebug.hpp"
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
    // GLfloat vVertices[] = {  0.0f,  0.5f, 0.0f,
    // 			     -0.5f, -0.5f, 0.0f,
    // 			     0.5f, -0.5f, 0.0f
    // };

    // glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 0, vVertices );

    // glDrawArrays ( GL_TRIANGLES, 0, 3 );
    // SLIM_GRAPHICS_GL_CHECK();

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
	SLIM_GRAPHICS_GL_CHECK();
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
    s_loader->generateVAO(data, m_vao);
    // TODO

    return true;
}


void
Mesh::setMaterial(const Material* material)
{
    m_material = material;
    this->listen(material);
}


void
Mesh::unloadData()
{
    m_vao.~VertexArrayObject();
}

}
}
