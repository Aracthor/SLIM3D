#ifndef SLIM_MATHS_LIB_HPP_
# define SLIM_MATHS_LIB_HPP_

# define _USE_MATH_DEFINES // MSC requirement for macros like M_PI
# include <cmath>

# ifdef M_PI
#  define SLIM_MATHS_PI	M_PI
# else
#  define SLIM_MATHS_PI	3.1415926
# endif

# define SLIM_MATHS_ABS(n)	(n < 0 ? -n : n)
# define SLIM_MATHS_MIN(a, b)	(a <= b ? a : b)
# define SLIM_MATHS_MAX(a, b)	(a >= b ? a : b)

namespace slim
{
namespace maths
{

namespace lib
{
template <typename T>
inline T		min(T a, T b);
template <typename T>
inline T		max(T a, T b);

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

inline float		acos(float angle);
inline double		acos(double angle);
inline long double	acos(long double angle);

inline float		asin(float angle);
inline double		asin(double angle);
inline long double	asin(long double angle);

inline float		atan(float angle);
inline double		atan(double angle);
inline long double	atan(long double angle);

template <typename T>
inline T		lerp(T a, T b, T ratio);

}

}
}

# include "lib.ipp"

#endif // !SLIM_MATHS_LIB_HPP_
