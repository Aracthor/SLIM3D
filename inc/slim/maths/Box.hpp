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
    inline bool			contains(const Vector3<T>& point) const;
    inline bool			contains(const Box<T>& box) const;
    inline bool			intersects(const Box<T>& box) const;

public:
    void	reset();
    void        addPoint(const Vector3<T>& point);
    void        addBox(const Box<T>& box);

private:
    Vector3<T>	m_min;
    Vector3<T>	m_max;
};

typedef Box<float>		Boxf;
typedef Box<double>		Boxd;
typedef Box<long double>	Boxld;
typedef Box<int>		Boxi;
typedef Box<unsigned int>	Boxui;
typedef Box<long>		Boxl;
typedef Box<unsigned long>	Boxul;

}

typedef	maths::Boxf	Box;

}

# include "Box.ipp"

#endif // !SLIM_MATHS_BOX_HPP_
