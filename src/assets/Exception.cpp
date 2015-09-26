#include "slim/assets/Exception.hh"

namespace slim
{
namespace assets
{

Exception::Exception(const Asset& asset, const char* message, const char* file, const char* function, int line) :
    debug::Exception(message, file, function, line),
    m_asset(asset)
{
    // TODO
}

Exception::~Exception()
{
}

}
}
