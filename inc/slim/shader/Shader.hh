#ifndef SLIM_SHADER_SHADER_HH_
# define SLIM_SHADER_SHADER_HH_

# include "slim/assets/SingleFileAsset.hh"
# include "slim/graphics/gl.h"

# define SLIM_SHADER_FILE_BUFFER_SIZE	0x10000

namespace slim
{
namespace shader
{

class	Shader : public assets::SingleFileAsset
{
public:
    enum	EType
    {
	VERTEX = GL_VERTEX_SHADER,
	FRAGMENT = GL_FRAGMENT_SHADER
    };

public:
    static const char* const	typeName;

public:
    Shader(const char* name, EType type);
    ~Shader();

public:
    inline EType	getType() const;
    inline GLuint	getId() const;

public:
    bool		loadFromFile(const char* const path) override;
    void		unloadData() override;

private:
    bool		readFromData(const char* const data);

private:
    EType		m_type;
    GLuint		m_id;
};

}
}

# include "Shader.hpp"

#endif // !SLIM_SHADER_SHADER_HH_