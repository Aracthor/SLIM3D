#ifndef SLIM_GRAPHICS_I_BINDABLE_HPP_
# define SLIM_GRAPHICS_I_BINDABLE_HPP_

namespace slim
{
namespace graphics
{

class	IBindable
{
public:
    virtual ~IBindable() {}

public:
    virtual void	bind() const = 0;
    virtual void	unbind() const = 0;
};

}
}

#endif // !SLIM_GRAPHICS_I_BINDABLE_HPP_
