#include "slim/context/Context.hh"
#include "slim/context/ContextImplementation.hh"

namespace slim
{
namespace context
{

Context
Context::instance;


Context::Context()
{
}

Context::~Context()
{
}


void
Context::onInit()
{
    m_implementation = new ContextImplementation();
}

void
Context::onDestroy()
{
    delete m_implementation;
}

}
}
