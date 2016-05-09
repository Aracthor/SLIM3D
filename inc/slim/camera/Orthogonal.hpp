#ifndef SLIM_CAMERA_ORTHOGONAL_HPP_
# define SLIM_CAMERA_ORTHOGONAL_HPP_

# include "slim/camera/Camera.hpp"
# include "slim/window/Window.hpp"

# define SLIM_CAMERA_DEFAULT_X_LENGTH	slim::window::Window::getCurrent()->getWidth()
# define SLIM_CAMERA_DEFAULT_Y_LENGTH	slim::window::Window::getCurrent()->getHeight()
# define SLIM_CAMERA_DEFAULT_Z_LENGTH	100.0

namespace slim
{
namespace camera
{

class	Orthogonal : public Camera
{
public:
    Orthogonal(float left = 0, float right = SLIM_CAMERA_DEFAULT_X_LENGTH,
	       float bottom = SLIM_CAMERA_DEFAULT_Y_LENGTH, float top = 0,
	       float rangeMin = 0, float rangeMax = SLIM_CAMERA_DEFAULT_Z_LENGTH);
    Orthogonal(const Orthogonal& reference);
    virtual ~Orthogonal();

public:
    inline float	getLeft() const;
    inline float	getRight() const;
    inline float	getBottom() const;
    inline float	getTop() const;
    inline float	getRangeMin() const;
    inline float	getRangeMax() const;

public:
    inline void		setLeft(float left);
    inline void		setRight(float right);
    inline void		setBottom(float bottom);
    inline void		setTop(float top);
    inline void		setRangeMin(float rangeMin);
    inline void		setRangeMax(float rangeMax);

public:
    inline void		getProjectionMatrix(Matrix4x4& matrix) const override;

private:
    float	m_left;
    float	m_right;
    float	m_bottom;
    float	m_top;
    float	m_rangeMin;
    float	m_rangeMax;
};

}
}

# include "Orthogonal.ipp"

#endif // !SLIM_CAMERA_ORTHOGONAL_HPP_
