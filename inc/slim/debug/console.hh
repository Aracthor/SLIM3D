#ifndef SLIM_DEBUG_CONSOLE_HH_
# define SLIM_DEBUG_CONSOLE_HH_

# include <ostream>

namespace slim
{
namespace debug
{

namespace console
{

enum	EColor
{
    black = 0,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white
};

enum	EEffect
{
    nothing = 0,
    bold = 1,
    subdued = 2,
    underlined = 4,
    highlighted = 7,
    barred = 9
};

}

}
}

std::ostream&	operator<<(std::ostream& stream, slim::debug::console::EColor color);
std::ostream&	operator<<(std::ostream& stream, slim::debug::console::EEffect color);

#endif // !SLIM_DEBUG_CONSOLE_HH_
