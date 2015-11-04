#include "slim/attributes.h"

// Windows seems to not handle color in its terminal,
// So those fonctions are just empty here.

std::ostream&
operator<<(std::ostream& stream, SLIM_CORE_UNUSED(slim::debug::console::EColor, color))
{
    return stream;
}

std::ostream&
operator<<(std::ostream& stream, SLIM_CORE_UNUSED(slim::debug::console::EEffect, effect))
{
    return stream;
}
