#include "slim/camera/Orthogonal.hpp"

namespace slim
{
namespace camera
{

Orthogonal::Orthogonal(float left, float right, float bottom, float top, float rangeMin, float rangeMax) :
    Camera(),
    m_left(left),
    m_right(right),
    m_bottom(bottom),
    m_top(top),
    m_rangeMin(rangeMin),
    m_rangeMax(rangeMax)
{
}

Orthogonal::Orthogonal(const Orthogonal& reference) :
    Camera(reference),
    m_left(reference.getLeft()),
    m_right(reference.getRight()),
    m_bottom(reference.getBottom()),
    m_top(reference.getTop()),
    m_rangeMin(reference.getRangeMin()),
    m_rangeMax(reference.getRangeMax())
{
}

Orthogonal::~Orthogonal()
{
}

}
}
