//
// Dumper.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Wed Sep  9 13:28:08 2015 Aracthor
// Last Update Wed Sep  9 13:35:26 2015 Aracthor
//

#ifndef SLIM3D_DEBUG_DUMPER_HH_
# define SLIM3D_DEBUG_DUMPER_HH_

# include "slim3d/maths/Vector2.hh"
# include "slim3d/maths/Vector3.hh"
# include "slim3d/maths/Vector4.hh"
# include "slim3d/maths/Matrix4x4.hh"

namespace slim
{

// Used class here as prototypes instead of includes because of compilation time
namespace maths
{
}

namespace debug
{

class	Dumper
{
public:
    Dumper();
    ~Dumper();

public:
    template <typename T>
    void	dump(const maths::Vector2<T>& vector, char* buffer, unsigned int bufferSize);
    // template <typename T>
    // void	dump(const maths::Vector3<T>& vector, char* buffer, unsigned int bufferSize);
    // template <typename T>
    // void	dump(const maths::Vector4<T>& vector, char* buffer, unsigned int bufferSize);
    // template <typename T>
    // void	dump(const maths::Matrix4x4<T>& vector, char* buffer, unsigned int bufferSize);
};

}
}

# include "Dumper.hpp"

#endif // !SLIM3D_DEBUG_DUMPER_HH_
