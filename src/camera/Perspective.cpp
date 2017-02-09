#include "slim/camera/Perspective.hpp"

namespace slim
{
namespace camera
{

Perspective::Perspective(float screenWidth, float screenHeight, float fov, float rangeMin, float rangeMax) :
    Camera(),
    m_fov(fov),
    m_aspectRatio(screenWidth / screenHeight),
    m_rangeMin(rangeMin),
    m_rangeMax(rangeMax)
{
}

Perspective::Perspective(const Perspective& reference) :
    Camera(reference),
    m_fov(reference.getFOV()),
    m_aspectRatio(reference.getAspectRatio()),
    m_rangeMin(reference.getRangeMin()),
    m_rangeMax(reference.getRangeMax())
{
}

Perspective::~Perspective()
{
}

}
}
