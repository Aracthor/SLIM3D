#ifndef SLIM_MESH_OBJ_LOADER_HPP_
# define SLIM_MESH_OBJ_LOADER_HPP_

# include "slim/containers/TokensPack.hpp"
# include "slim/mesh/FileLoader.hpp"
# include "slim/memory/Chunk.hpp"

# include "slim/memory/units.h"

# define SLIM_MESH_OBJ_FILE_MAX_SIZE		(10 * SLIM_MEMORY_MEBIBYTE)
# define SLIM_MESH_OBJ_FILE_COMMENT_CHAR	'#'
# define SLIM_MESH_OBJ_FILE_COMMAND_NUMBER	4

namespace slim
{
namespace mesh
{

class		ObjLoader : public FileLoader
{
public:
    ObjLoader(memory::Chunk& memory);
    ~ObjLoader();

public:
    bool	readFile(io::VirtualFile& file, FileLoader::Data& dest) override;

private:
    void	cleanLine(char* line) const;
    void	interpreteLine(char* line, unsigned int lineNumber);

private:
    bool	addCoord(containers::TokensPack& tokens);
    bool	addTextureCoord(containers::TokensPack& tokens);
    bool	addNormal(containers::TokensPack& tokens);
    bool	addIndex(containers::TokensPack& tokens);

private:
    char		m_buffer[SLIM_MESH_OBJ_FILE_MAX_SIZE];
    const char*		m_commandNames[SLIM_MESH_OBJ_FILE_COMMAND_NUMBER];
    bool		(ObjLoader::*m_commands[SLIM_MESH_OBJ_FILE_COMMAND_NUMBER])(containers::TokensPack&);

    Position*		m_tempPositions;
    TextureCoord*	m_tempTexCoords;
    Normal*		m_tempNormals;
    unsigned int	m_positionsNumber;
    unsigned int	m_texCoordsNumber;
    unsigned int	m_normalsNumber;

    const char*		m_currentFileName;
    FileLoader::Data*	m_currentDest;
};

}
}

#endif // !SLIM_MESH_OBJ_LOADER_HPP_
