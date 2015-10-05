#include <X11/Xlib.h>

namespace slim
{
namespace context
{

class	ContextImplementation : public IContextImplementation
{
public:
    ContextImplementation();
    ~ContextImplementation();

public:
    inline Display*	getDisplay();

private:
    Display*		m_display;
};

}
}

#include "ContextImplementation.hpp"
