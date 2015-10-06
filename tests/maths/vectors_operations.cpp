#include <iostream>

#include "slim/maths/Vector4.hpp"

using namespace slim;

static int	test(int (function)(), const char* name)
{
    int		return_value = !function();

    if (return_value != 0)
    {
	std::cerr << "TEST FAIL: " << name << std::endl;
    }

    return return_value;
}

static int	additions()
{
    Vector4	a(1.0f, 5.0f, -2.0f, 0.0f);
    Vector4	b(-5.4f, 0.0f, -11.0f, 42.0f);

    Vector4	c = a + b;

    b += a;

    return (b.x == -4.4f && b.y == 5.0f && b.z == -13.0f && b.w == 42.0f &&
	    c.x == -4.4f && c.y == 5.0f && c.z == -13.0f && c.w == 42.0f);
}

static int	substractions()
{
    Vector4	a(1.0f, 5.0f, -2.0f, 0.0f);
    Vector4	b(-5.4f, 0.0f, -11.0f, 42.0f);

    Vector4	c = a - b;

    b -= a;

    return (b.x == -6.4f && b.y == -5.0f && b.z == -9.0f && b.w == 42.0f &&
	    c.x == 6.4f && c.y == 5.0f && c.z == 9.0f && c.w == -42.0f);
}

static int	scales()
{
    Vector4	a(1.0f, 5.0f, -2.0f, 0.0f);
    Vector4	b(-5.4f, 0.0f, -11.0f, 42.0f);

    Vector4	c = a.scale(2);

    b.unscaleTo(0.5);

    return (b.x == -10.8f && b.y == 0.0f && b.z == -22.0f && b.w == 84.0f &&
	    c.x == 2.0f && c.y == 10.0f && c.z == -4.0f && c.w == 0.0f);
}

int	main()
{
    return (test(additions, "additions") == 0 &&
	    test(substractions, "substractions") == 0 &&
	    test(scales, "scales") == 0);
}
