#include "slim/io/BufferedReadingFile.hh"
#include "slim/shader/Shader.hh"
#include "slim/shader/Program.hh"

#include "HelloWorldShader.hh"

HelloWorldShader::HelloWorldShader()
{
    m_windowParameters.width = 800;
    m_windowParameters.height = 600;
    m_windowParameters.fullscreen = false;
    m_windowParameters.title = "SLIM3D samples - hello world shader";
}

HelloWorldShader::~HelloWorldShader()
{
}


void
HelloWorldShader::onInit()
{
    slim::io::BufferedReadingFile	vertexShaderFile("../../samples/resources/shaders/basic.vert");
    slim::io::BufferedReadingFile	fragmentShaderFile("../../samples/resources/shaders/basic.frag");

    slim::shader::Shader	vertexShader(slim::shader::Shader::VERTEX, vertexShaderFile);
    slim::shader::Shader	fragmentShader(slim::shader::Shader::FRAGMENT, fragmentShaderFile);
    slim::shader::Program	program("Test program", vertexShader, fragmentShader);

    this->stop();
}
