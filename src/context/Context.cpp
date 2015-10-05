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


bool
Context::onInit()
{
    m_implementation = new ContextImplementation();

    return true;
}

void
Context::onDestroy()
{
    delete m_implementation;
}

}
}
