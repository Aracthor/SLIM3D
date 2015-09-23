#ifndef SLIM_SHADER_SHADER_HH_
# define SLIM_SHADER_SHADER_HH_

# include "slim/resources/ReadingFile.hh"
# include "slim/resources/VirtualFile.hh"

# include "slim/graphics/gl.h"

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
    Shader(EType type, resources::ReadingFile& file);
    Shader(const char* name, EType type, resources::VirtualFile& file);
    Shader(const char* name, EType type, const char* data);
    ~Shader();

public:
    inline const char*	getName() const;
    inline EType	getType() const;
    inline GLuint	getId() const;

private:
    void	readFromFile(resources::ReadingFile& file);
    void	readFromFile(const resources::VirtualFile& file);
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
