#ifndef SLIM_SHADER_PROGRAM_HH_
# define SLIM_SHADER_PROGRAM_HH_

# include "slim/shader/Shader.hh"

namespace slim
{
namespace shader
{

class	Program
{
public:
    Program(const char* name, const Shader& vertexShader, const Shader& fragmentShader);
    ~Program();

private:
    const char*	m_name;
    GLint	m_id;
};

}
}

# include "Program.hpp"

#endif // !SLIM_SHADER_PROGRAM_HH_
