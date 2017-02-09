#ifndef SLIM_CAMERA_PERSPECTIVE_HPP_
# define SLIM_CAMERA_PERSPECTIVE_HPP_

# include "slim/camera/Camera.hpp"

# define SLIM_CAMERA_DEFAULT_FOV	80.0
# define SLIM_CAMERA_DEFAULT_RANGE_MIN	0.1
# define SLIM_CAMERA_DEFAULT_RANGE_MAX	1000.0

namespace slim
{
namespace camera
{

class	Perspective : public Camera
{
public:
    Perspective(float screenWidth, float screenHeight,
		float fov = SLIM_CAMERA_DEFAULT_FOV,
		float rangeMin = SLIM_CAMERA_DEFAULT_RANGE_MIN,
		float rangeMax = SLIM_CAMERA_DEFAULT_RANGE_MAX);
    Perspective(const Perspective& reference);
    virtual ~Perspective();

public:
    inline float	getFOV() const;
    inline float	getAspectRatio() const;
    inline float	getRangeMin() const;
    inline float	getRangeMax() const;

public:
    inline void		setFOV(float fov);
    inline void		setAspectRatio(float screenWidth, float screenHeight);
    inline void		setRangeMin(float rangeMin);
    inline void		setRangeMax(float rangeMax);

public:
    inline void		getProjectionMatrix(Matrix4x4& matrix) const override;

private:
    float	m_fov;
    float	m_aspectRatio;
    float	m_rangeMin;
    float	m_rangeMax;
};

}
}

# include "Perspective.ipp"

#endif // !SLIM_CAMERA_PERSPECTIVE_HPP_
