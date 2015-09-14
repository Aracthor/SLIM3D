#include "slim/debug/Log.hh"

namespace slim
{
namespace debug
{

void
LogStream::setActive(bool active)
{
    m_active = active;
}


template <typename T>
LogStream&
LogStream::operator<<(const T& object)
{
    if (m_active)
    {
	m_buffer << object;
    }

    return *this;
}

}
}
