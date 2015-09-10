//
// lib.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Sat Sep  5 12:28:48 2015 Aracthor
// Last Update Thu Sep 10 20:49:01 2015 Aracthor
//

#ifndef SLIM3D_MATHS_LIB_HH_
# define SLIM3D_MATHS_LIB_HH_

# include <cmath>

# define SLIM3D_MATHS_PI	M_PI

namespace slim
{
namespace maths
{

namespace lib
{
inline float		sqrt(float n);
inline double		sqrt(double n);
inline long double	sqrt(long double n);

inline float		cos(float angle);
inline double		cos(double angle);
inline long double	cos(long double angle);

inline float		sin(float angle);
inline double		sin(double angle);
inline long double	sin(long double angle);

inline float		tan(float angle);
inline double		tan(double angle);
inline long double	tan(long double angle);

template <typename T>
inline T		lerp(T a, T b, T ratio);

# include "lib.hpp"
}

}
}

#endif // !SLIM3D_MATHS_LIB_HH_
