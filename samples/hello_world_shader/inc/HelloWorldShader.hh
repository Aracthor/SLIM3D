#ifndef HELLO_WORD_SHADER_HH_
# define HELLO_WORD_SHADER_HH_

# include "slim/engine/Engine.hh"
# include "slim/shader/Program.hh"
# include "slim/shader/Shader.hh"

class	HelloWorldShader : public slim::engine::Engine
{
public:
    HelloWorldShader(int argc, char** argv);
    ~HelloWorldShader();

public:
    void	onInit() override;
    void	onShutdown() override;

private:
    slim::shader::Shader*	m_vertexShader;
    slim::shader::Shader*	m_fragmentShader;
    slim::shader::Program*	m_program;
};

#endif // !HELLO_WORD_SHADER_HH_
