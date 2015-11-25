#ifndef SLIM_CAMERA_FREE_FLY_LISTENERS_HPP_
# define SLIM_CAMERA_FREE_FLY_LISTENERS_HPP_

# include "slim/camera/FreeFly.hpp"
# include "slim/events/IListener.hpp"

namespace slim
{
namespace camera
{

namespace freefly
{

class	Listener
{
public:
    explicit Listener(FreeFly& camera);
    virtual ~Listener();

protected:
    FreeFly&	m_camera;
};


class	MoveFront : public Listener,
		     public events::IListener
{
public:
    explicit MoveFront(FreeFly& camera);
    ~MoveFront();

public:
    void	onEvent() override;
};

class	MoveBack : public Listener,
		     public events::IListener
{
public:
    explicit MoveBack(FreeFly& camera);
    ~MoveBack();

public:
    void	onEvent() override;
};

}

}
}

#endif // !SLIM_CAMERA_FREE_FLY_LISTENERS_HPP_
