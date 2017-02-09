#include <iostream>

#include "slim/maths/Vector4.hpp"
#include "slim/time/Clock.hpp"

#define TESTS_NUMBER	10000000

void
float3_assignement_test()
{
    slim::time::Clock	clock;
    int			i;
    float		x1, y1, z1;
    float		x2, y2, z2;

    x1 = 1.0;
    y1 = 2.0;
    z1 = 3.0;

    clock.reset();
    {
	for (i = 0; i < TESTS_NUMBER; ++i)
	{
	    x2 = x1;
	    y2 = y1;
	    z2 = z1;
	}
    }

    (void)x2;
    (void)y2;
    (void)z2;

    clock.update();
    std::cout << "Elpased time for 3 raw floats:\t" << clock.getElapsedTime() << "us." << std::endl;
}

void
float4_assignement_test()
{
    slim::time::Clock	clock;
    int			i;
    float		x1, y1, z1, w1;
    float		x2, y2, z2, w2;

    x1 = 1.0;
    y1 = 2.0;
    z1 = 3.0;
    w1 = 4.0;

    clock.reset();
    {
	for (i = 0; i < TESTS_NUMBER; ++i)
	{
	    x2 = x1;
	    y2 = y1;
	    z2 = z1;
	    w2 = w1;
	}
    }

    (void)x2;
    (void)y2;
    (void)z2;
    (void)w2;

    clock.update();
    std::cout << "Elpased time for 4 raw floats:\t" << clock.getElapsedTime() << "us." << std::endl;
}

#if __SSE__ == 1
# include <xmmintrin.h>
void
sse_assignement_test()
{
    slim::time::Clock	clock;
    int			i;
    const float		data[] = {1.0, 2.0, 3.0, 4.0};
    __m128		src;
    __m128		dest;

    src = _mm_load_ps(data);

    clock.reset();
    {
	for (i = 0; i < TESTS_NUMBER; ++i)
	{
	    src = _mm_load_ps(data);
	    dest = src;
	}
    }

    (void)dest;

    clock.update();
    std::cout << "Elpased time for __m128:\t" << clock.getElapsedTime() << "us." << std::endl;
}
#else
void
sse_assignement_test()
{
    std::cerr << "This system does not support SSE operations." << std::endl;
}
#endif

int
main()
{
    float3_assignement_test();
    float4_assignement_test();
    sse_assignement_test();

    return 0;
}
