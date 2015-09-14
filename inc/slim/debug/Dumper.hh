#ifndef SLIM_DEBUG_DUMPER_HH_
# define SLIM_DEBUG_DUMPER_HH_

# include "slim/maths/Vector2.hh"
# include "slim/maths/Vector3.hh"
# include "slim/maths/Vector4.hh"
# include "slim/maths/Matrix4x4.hh"

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

#endif // !SLIM_DEBUG_DUMPER_HH_
