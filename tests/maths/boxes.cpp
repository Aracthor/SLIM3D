#include <iostream>

#include "slim/maths/Box.hpp"

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

static int	creation()
{
    Box		box1(40, 40, 20);

    box1.addPoint(-5, 10, -45);
    box1.addPoint(-25, 30, -42);

    Box		box2(box1);

    box2.addPoint(75, -10, 10);

    const Vector3&	min1 = box1.getMin();
    const Vector3&	min2 = box2.getMin();
    const Vector3&	max1 = box1.getMax();
    const Vector3&	max2 = box2.getMax();

    return (min1.x == -25 && min1.y == 10 && min1.z == -45 &&
	    min2.x == -25 && min2.y == -10 && min2.z == -45 &&
	    max1.x == 40 && max1.y == 40 && max1.z == 20 &&
	    max2.x == 75 && max2.y == 40 && max2.z == 20);
}

static int	intersections()
{
    Box		box(40, 40, 20);

    box.addPoint(-5, 10, -45);
    box.addPoint(-25, 30, -42);

    return (box.contains(30, 30, 20) && box.contains(-20, 15, 0) &&
	    !box.contains(0, 0, 0) && !box.contains(-40, -40, -40));
}

int	main()
{
    return (test(creation, "creation") == 0 &&
	    test(intersections, "intersections") == 0);
}
