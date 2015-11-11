#include "slim/maths/Vector4.hpp"

#if __SSE__ == 1
# include "SSE/Vector4.cpp"
#endif
