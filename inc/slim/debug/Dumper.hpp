#include <cstdio>

namespace slim
{
namespace debug
{

template <typename T>
void
Dumper::dump(const maths::Vector2<T>& vector, char* buffer, unsigned int bufferSize)
{
    snprintf(buffer, bufferSize, "(%f,%f)", vector.x, vector.y);
}

}
}
