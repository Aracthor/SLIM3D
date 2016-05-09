#ifndef SLIM_CAMERA_CAMERA_HPP_
# define SLIM_CAMERA_CAMERA_HPP_

# include "slim/maths/Vector3.hpp"
# include "slim/maths/Matrix4x4.hpp"
# include "slim/time/Clock.hpp"

namespace slim
{
namespace camera
{

class	Camera
{
public:
    Camera();
    Camera(const Camera& reference);
    virtual ~Camera();

public:
    inline const Vector3&	getPosition() const;
    inline const Vector3&	getTarget() const;
    inline const Vector3&	getUp() const;

public:
    inline void			setPosition(float x, float y, float z);
    inline void			setPosition(const Vector3& position);
    inline void			setTarget(float x, float y, float z);
    inline void			setTarget(const Vector3& target);
    inline void			setUp(float x, float y, float z);
    inline void			setUp(const Vector3& up);

public:
    void			getViewMatrix(Matrix4x4& matrix) const;
    virtual void		getProjectionMatrix(Matrix4x4& matrix) const = 0;

public:
    virtual void	        update(time::Clock::time elapsedTime);

protected:
    Vector3	m_position;
    Vector3	m_target;
    Vector3	m_up;
};

}
}

# include "Camera.ipp"

#endif // !SLIM_CAMERA_CAMERA_HPP_
