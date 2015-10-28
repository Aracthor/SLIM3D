#include "HelloWorldShader.hpp"

HelloWorldShader::HelloWorldShader(int argc, char** argv) :
    slim::engine::Engine(argc, argv)
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
    m_vertexShader = slim::assets::Asset::create<slim::shader::Shader>("basic.vert", slim::shader::Shader::VERTEX);
    m_fragmentShader = slim::assets::Asset::create<slim::shader::Shader>("basic.frag", slim::shader::Shader::FRAGMENT);
    m_program = slim::assets::Asset::create<slim::shader::Program>("basic", m_vertexShader, m_fragmentShader);

    m_program->setNeeded(true);
    slim::assets::Manager::instance.loadNeededAssets();

    this->stop();
}


void
HelloWorldShader::onShutdown()
{
    delete m_vertexShader;
    delete m_fragmentShader;
}
