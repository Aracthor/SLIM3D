//
// Dumper.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Wed Sep  9 13:35:31 2015 Aracthor
// Last Update Wed Sep  9 13:37:01 2015 Aracthor
//

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
