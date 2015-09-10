//
// lib.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Sat Sep  5 12:35:21 2015 Aracthor
// Last Update Thu Sep 10 20:50:24 2015 Aracthor
//

float
sqrt(float n)
{
    return (::sqrtf(n));
}

double
sqrt(double n)
{
    return (::sqrt(n));
}

long double
sqrt(long double n)
{
    return (::sqrtl(n));
}


float
cos(float angle)
{
    return (::cosf(angle));
}

double
cos(double angle)
{
    return (::cos(angle));
}

long double
cos(long double angle)
{
    return (::cosl(angle));
}


float
sin(float angle)
{
    return (::sinf(angle));
}

double
sin(double angle)
{
    return (::sin(angle));
}

long double
sin(long double angle)
{
    return (::sinl(angle));
}


float
tan(float angle)
{
    return (::tanf(angle));
}

double
tan(double angle)
{
    return (::tan(angle));
}

long double
tan(long double angle)
{
    return (::tanl(angle));
}


template <typename T>
T
lerp(T a, T b, T ratio)
{
    // Unperfect but quick method
    return (a + ratio * (b - a));
    // Perfect but slow method
    // return ((1.0 - ratio) * a + ratio * b);
}
