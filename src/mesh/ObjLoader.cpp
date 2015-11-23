#include "slim/debug/LogManager.hpp"
#include "slim/mesh/ObjLoader.hpp"

#include "slim/stdlib.h"

namespace slim
{
namespace mesh
{

ObjLoader::ObjLoader(memory::Chunk& memory) :
    FileLoader(memory)
{
    m_commandNames[0] = "v";	m_commands[0] = &ObjLoader::addCoord;
    m_commandNames[1] = "vt";	m_commands[1] = &ObjLoader::addTextureCoord;
    m_commandNames[2] = "vn";	m_commands[2] = &ObjLoader::addNormal;
    m_commandNames[3] = "f";	m_commands[3] = &ObjLoader::addIndex;
}

ObjLoader::~ObjLoader()
{
}


bool
ObjLoader::readFile(io::VirtualFile& file, FileLoader::Data& dest)
{
    m_currentFileName = file.getName();
    m_currentDest = &dest;

    file.toBuffer(m_buffer, SLIM_MESH_OBJ_FILE_MAX_SIZE);

    containers::TokensPack	lines(m_buffer);
    char*			line;
    unsigned int		lineNumber = 0;

    while ((line = lines.getNextToken()) != nullptr)
    {
	lineNumber++;

	this->cleanLine(line);

	if (line[0] != '\0')
	{
	    this->interpreteLine(line, lineNumber);
	}
    }

    return true;
}


void
ObjLoader::cleanLine(char* line) const
{
    char*	ptr;
    int		i;

    // Delete comment part
    ptr = strchr(line, SLIM_MESH_OBJ_FILE_COMMENT_CHAR);
    if (ptr != nullptr)
    {
	*ptr = '\0';
    }

    // Delete last spaces and tabulations
    i = strlen(line) - 1;
    while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
    {
	line[i] = '\0';
	i--;
    }
}

void
ObjLoader::interpreteLine(char* line, unsigned int lineNumber)
{
    containers::TokensPack	tokens(line, ' ');
    const char*			command = tokens.getNextToken();
    unsigned int		i;

    for (i = 0; i < SLIM_MESH_OBJ_FILE_COMMAND_NUMBER; i++)
    {
	if (!strcmp(command, m_commandNames[i]))
	{
	    if ((this->*m_commands[i])(tokens) == false)
	    {
		debug::LogManager::instance.assets.warning << "Syntax error on line " << lineNumber << " in file " << m_currentFileName << debug::LogStream::endline;
	    }
	    break;
	}
    }

    if (i == SLIM_MESH_OBJ_FILE_COMMAND_NUMBER)
    {
	debug::LogManager::instance.assets.warning << "Unrecognized command " << command << " in file " << m_currentFileName << debug::LogStream::endline;
    }
}


bool
ObjLoader::addCoord(containers::TokensPack& tokens)
{
    const char*	x = tokens.getNextToken();
    const char*	y = tokens.getNextToken();
    const char*	z = tokens.getNextToken();

    if (x == nullptr || y == nullptr || z == nullptr)
    {
	return false;
    }

    m_positionsNumber++;
    m_tempPositions = m_memory.realloc(m_tempPositions, m_positionsNumber * sizeof(Position));

    Position&	position = m_tempPositions[m_positionsNumber - 1];
    position.x = strtof(x, nullptr);
    position.y = strtof(y, nullptr);
    position.z = strtof(z, nullptr);

    return true;
}

bool
ObjLoader::addTextureCoord(containers::TokensPack& tokens)
{
    const char*	x = tokens.getNextToken();
    const char*	y = tokens.getNextToken();

    if (x == nullptr || y == nullptr)
    {
	return false;
    }

    m_texCoordsNumber++;
    m_tempTexCoords = m_memory.realloc(m_tempTexCoords, m_texCoordsNumber * sizeof(Position));
    TextureCoord&	textureCoord = m_tempTexCoords[m_texCoordsNumber - 1];
    textureCoord.x = strtof(x, nullptr);
    textureCoord.y = strtof(y, nullptr);

    return true;
}

bool
ObjLoader::addNormal(containers::TokensPack& tokens)
{
    const char*	x = tokens.getNextToken();
    const char*	y = tokens.getNextToken();
    const char*	z = tokens.getNextToken();

    if (x == nullptr || y == nullptr || z == nullptr)
    {
	return false;
    }

    m_normalsNumber++;
    m_tempNormals = m_memory.realloc(m_tempNormals, m_normalsNumber * sizeof(Normal));
    Normal&	normal = m_tempNormals[m_normalsNumber - 1];
    normal.x = strtof(x, nullptr);
    normal.y = strtof(y, nullptr);
    normal.z = strtof(z, nullptr);

    return true;
}

bool
ObjLoader::addIndex(containers::TokensPack& tokens)
{
    containers::TokensPack	tokenPacks[3] =
	{
	    containers::TokensPack(tokens.getNextToken(), '/'),
	    containers::TokensPack(tokens.getNextToken(), '/'),
	    containers::TokensPack(tokens.getNextToken(), '/')
	};
    unsigned int		i;
    
    for (i = 0; i < 3; i++)
    {
	containers::TokensPack&	tokens = tokenPacks[i];
	const char*		token;

        m_currentDest->number++;
	m_currentDest->vertices = m_memory.realloc(m_currentDest->vertices,
						   m_currentDest->number * sizeof(Vertex));

	Vertex&	vertex = m_currentDest->vertices[m_currentDest->number - 1];

	// Position
	token = tokens.getNextToken();
	SLIM_DEBUG_ASSERT(atoi(token) - 1 < static_cast<int>(m_positionsNumber));
	vertex.position = m_tempPositions[atoi(token) - 1];

	// TextureCoord
	token = tokens.getNextToken();
	if (token != nullptr && token[0] != '\0')
	{
	    SLIM_DEBUG_ASSERT(atoi(token) - 1 < static_cast<int>(m_texCoordsNumber));
	    vertex.texCoord = m_tempTexCoords[atoi(token) - 1];
	}

	// Normal
	token = tokens.getNextToken();
	if (token != nullptr && token[0] != '\0')
	{
	    SLIM_DEBUG_ASSERT(atoi(token) - 1 < static_cast<int>(m_normalsNumber));
	    vertex.normal = m_tempNormals[atoi(token) - 1];
	}
    }

    return true;
}


}
}
