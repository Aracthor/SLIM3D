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

class	MoveRight : public Listener,
		    public events::IListener
{
public:
    explicit MoveRight(FreeFly& camera);
    ~MoveRight();

public:
    void	onEvent() override;
};

class	MoveLeft : public Listener,
		   public events::IListener
{
public:
    explicit MoveLeft(FreeFly& camera);
    ~MoveLeft();

public:
    void	onEvent() override;
};

class	MouseMovement : public Listener,
			public events::IMouseListener
{
public:
    explicit MouseMovement(FreeFly& camera);
    ~MouseMovement();

public:
    void	onEvent(const Vector2& position) override;
};

}

}
}

#endif // !SLIM_CAMERA_FREE_FLY_LISTENERS_HPP_
