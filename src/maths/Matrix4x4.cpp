#include "slim/maths/Matrix4x4.hpp"

#if __SSE__ == 1
# include "SSE/Matrix4x4.cpp"
#endif
