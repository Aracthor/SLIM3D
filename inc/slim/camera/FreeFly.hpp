#ifndef SLIM_CAMERA_FREE_FLY_HPP_
# define SLIM_CAMERA_FREE_FLY_HPP_

# include "slim/camera/Perspective.hpp"
# include "slim/events/IListenerPack.hpp"
# include "slim/window/Window.hpp"

# define SLIM_CAMERA_FREE_FLY_DEFAULT_INERTIA		0.95
# define SLIM_CAMERA_FREE_FLY_DEFAULT_SPEED		0.00001
# define SLIM_CAMERA_FREE_FLY_DEFAULT_SENSITIVITY	0.005
# define SLIM_CAMERA_FREE_FLY_MAX_ANGLE_Y		SLIM_MATHS_PI / 2.0f - 0.2f

namespace slim
{
namespace camera
{

class	FreeFly : public Perspective,
		  public events::IListenerPack
{
public:
    FreeFly(window::Window* window = window::Window::getCurrent(),
	    float fov = SLIM_CAMERA_DEFAULT_FOV,
	    float rangeMin = SLIM_CAMERA_DEFAULT_RANGE_MIN,
	    float rangeMax = SLIM_CAMERA_DEFAULT_RANGE_MAX);
    FreeFly(const FreeFly& reference);
    ~FreeFly();

public:
    inline float	getInertia() const;
    inline float	getSpeed() const;
    inline float	getSensitivity() const;

public:
    inline void	advance(float speed);
    inline void	horizontalMove(float speed);

public:
    void	rotateX(float angle);
    void	rotateY(float angle);

public:
    void	registerEvents(events::Manager& manager) override;

public:
    void	update(time::Clock::time elapsedTime) override;

private:
    void	recalcVectors();

private:
    float	m_inertia = SLIM_CAMERA_FREE_FLY_DEFAULT_INERTIA;
    float	m_speed = SLIM_CAMERA_FREE_FLY_DEFAULT_SPEED;
    float	m_sensitivity = SLIM_CAMERA_FREE_FLY_DEFAULT_SENSITIVITY;

    Vector3	m_forward;
    Vector3	m_left;
    Vector3	m_move;

    float	m_angleX = 0.0;
    float	m_angleY = 0.0;
};

}
}

# include "FreeFly.ipp"

#endif // !SLIM_CAMERA_FREE_FLY_HPP_
