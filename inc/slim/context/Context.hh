#ifndef SLIM_CONTEXT_CONTEXT_HH_
# define SLIM_CONTEXT_CONTEXT_HH_

# include "slim/context/ContextImplementation.hh"
# include "slim/core/Singleton.hh"

namespace slim
{
namespace context
{

class	Context : public core::Singleton
{
public:
    static Context	instance;

public:
    Context();
    ~Context();

public:
    bool	onInit() override;
    void	onDestroy() override;

public:
    inline const ContextImplementation*	getImplementation() const;
    inline ContextImplementation*       getImplementation();

private:
    ContextImplementation*	m_implementation;
};

}
}

# include "Context.hpp"

#endif // !SLIM_CONTEXT_CONTEXT_HH_
