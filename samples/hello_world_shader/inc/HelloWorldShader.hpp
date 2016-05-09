#ifndef HELLO_WORD_SHADER_HPP_
# define HELLO_WORD_SHADER_HPP_

# include "slim/engine/Engine.hpp"
# include "slim/shader/Program.hpp"
# include "slim/shader/Shader.hpp"

class	HelloWorldShader : public slim::engine::Engine
{
public:
    HelloWorldShader(int argc, char** argv);
    ~HelloWorldShader();

public:
    void	onInit() override;

private:
    slim::shader::Shader*	m_vertexShader;
    slim::shader::Shader*	m_fragmentShader;
    slim::shader::Program*	m_program;
};

#endif // !HELLO_WORD_SHADER_HPP_
