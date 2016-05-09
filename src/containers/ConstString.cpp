#include "slim/containers/ConstString.hpp"

namespace slim
{
namespace containers
{

ConstString::ConstString(const char* data) :
    m_data(data)
{
}

ConstString::ConstString(const ConstString& reference) :
    m_data(reference.getData())
{
}

ConstString::~ConstString()
{
}

}
}
