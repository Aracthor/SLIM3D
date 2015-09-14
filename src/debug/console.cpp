#include "slim/debug/console.hh"

std::ostream&
operator<<(std::ostream& stream, slim::debug::console::EColor color)
{
    stream << 0x1B << "[3" << (color + '0') << 'm';

    return stream;
}

std::ostream&
operator<<(std::ostream& stream, slim::debug::console::EEffect effect)
{
    stream << 0x1B << "[0" << (effect + '0') << 'm';

    return stream;
}
