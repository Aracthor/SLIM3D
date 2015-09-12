//
// lib.hpp for SLIM in /home/aracthor/programs/projects/SLIM/maths
// 
// Made by Aracthor
// 
// Started on  Sat Sep  5 12:35:21 2015 Aracthor
// Last Update Fri Sep 11 12:57:34 2015 Aracthor
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


float
acos(float angle)
{
    return (::acosf(angle));
}

double
acos(double angle)
{
    return (::acos(angle));
}

long double
acos(long double angle)
{
    return (::acosl(angle));
}


float
asin(float angle)
{
    return (::asinf(angle));
}

double
asin(double angle)
{
    return (::asin(angle));
}

long double
asin(long double angle)
{
    return (::asinl(angle));
}


float
atan(float angle)
{
    return (::atanf(angle));
}

double
atan(double angle)
{
    return (::atan(angle));
}

long double
atan(long double angle)
{
    return (::atanl(angle));
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
