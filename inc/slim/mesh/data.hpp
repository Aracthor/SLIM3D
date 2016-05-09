#ifndef SLIM_MESH_DATA_HPP_
# define SLIM_MESH_DATA_HPP_

# include "slim/maths/Vector2.hpp"
# include "slim/maths/Vector3.hpp"
# include "slim/maths/Vector4.hpp"

# define SLIM_MESH_BLACK_COLOR	slim::mesh::Color(0.0, 0.0, 0.0, 1.0)
# define SLIM_MESH_WHITE_COLOR	slim::mesh::Color(1.0, 1.0, 1.0, 1.0)

namespace slim
{
namespace mesh
{

typedef Vector3		Position;
typedef Vector4		Color;
typedef Vector2		TextureCoord;
typedef Vector3		Normal;
typedef unsigned short	Index;

struct			Vertex
{
    Position		position;
    Color		color;
    TextureCoord	texCoord;
    Normal		normal;
};

}
}

#endif // !SLIM_MESH_DATA_HPP_
