#include "slim/core/stdio.h"
#include "slim/core/string.h"
#include "slim/debug/LogManager.hh"
#include "slim/io/ResourceException.hh"

namespace slim
{
namespace io
{

ResourceException::ResourceException(const char* resourceName, const char* message,
				     const char* file, const char* function, int line) :
    debug::Exception(message, file, function, line),
    m_resourceName(resourceName)
{
    char	newMessage[SLIM_DEBUG_MESSAGE_BUFFER_SIZE];

    snprintf(newMessage, SLIM_DEBUG_MESSAGE_BUFFER_SIZE, "Resource %s: %s", resourceName, m_whatMessage);
    strcpy(m_whatMessage, newMessage);

    debug::LogManager::instance.assets.error << "FatalError: " << m_whatMessage << debug::LogStream::endline;
}

ResourceException::~ResourceException() throw()
{
}

}
}
