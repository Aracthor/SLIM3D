#ifndef SLIM_MATHS_BOX_HPP_
# define SLIM_MATHS_BOX_HPP_

# include "slim/maths/Vector3.hpp"

namespace slim
{
namespace maths
{

template <typename T>
class	Box
{
public:
    Box();
    Box(const Box<T>& box);
    ~Box();

public:
    inline const Vector3<T>&	getMin() const;
    inline const Vector3<T>&	getMax() const;
    inline T			getWidth() const;
    inline T			getHeight() const;
    inline T			getDepth() const;

public:
    void	reset();
    void        addPoint(const Vector3<T>& point);
    void        addBox(const Box<T>& box);

private:
    Vector3<T>	m_min;
    Vector3<T>	m_max;
};

}
}

# include "Box.ipp"

#endif // !SLIM_MATHS_BOX_HPP_
