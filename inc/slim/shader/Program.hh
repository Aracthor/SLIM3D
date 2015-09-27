#ifndef SLIM_SHADER_PROGRAM_HH_
# define SLIM_SHADER_PROGRAM_HH_

# include "slim/assets/Asset.hh"
# include "slim/shader/Shader.hh"

namespace slim
{
namespace shader
{

class	Program : public assets::Asset
{
public:
    static const char* const	typeName;

public:
    Program(const char* name, const Shader* vertexShader, const Shader* fragmentShader);
    ~Program();

protected:
    void	onAssetsReady() override;
    void	onAssetsUnloaded() override;

private:
    GLint		m_id;
    const Shader*	m_vertexShader;
    const Shader*	m_fragmentShader;
};

}
}

# include "Program.hpp"

#endif // !SLIM_SHADER_PROGRAM_HH_
