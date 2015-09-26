#ifndef SLIM_SHADER_SHADER_HH_
# define SLIM_SHADER_SHADER_HH_

# include "slim/io/ReadingFile.hh"
# include "slim/io/VirtualFile.hh"

# include "slim/graphics/gl.h"

# define SLIM_SHADER_FILE_BUFFER_SIZE	0x10000

namespace slim
{
namespace shader
{

class	Shader
{
public:
    enum	EType
    {
	VERTEX = GL_VERTEX_SHADER,
	FRAGMENT = GL_FRAGMENT_SHADER
    };

public:
    Shader(EType type, io::ReadingFile& file);
    Shader(const char* name, EType type, io::VirtualFile& file);
    Shader(const char* name, EType type, const char* data);
    ~Shader();

public:
    inline const char*	getName() const;
    inline EType	getType() const;
    inline GLuint	getId() const;

private:
    void	readFromFile(io::ReadingFile& file);
    void	readFromFile(const io::VirtualFile& file);
    void	readFromData(const char* data);

private:
    const char*	m_name;
    EType	m_type;
    GLuint	m_id;
};

}
}

# include "Shader.hpp"

#endif // !SLIM_SHADER_SHADER_HH_
