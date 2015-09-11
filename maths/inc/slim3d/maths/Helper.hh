//
// Helper.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Fri Sep  4 16:06:31 2015 Aracthor
// Last Update Fri Sep 11 12:56:37 2015 Aracthor
//

#ifndef SLIM3D_MATHS_HELPER_HH_
# define SLIM3D_MATHS_HELPER_HH_

# include "slim3d/core/Singleton.hh"
# include "slim3d/debug/assert.hh"
# include "slim3d/maths/lib.hh"

# define SLIM3D_MATHS_HELPER_PRECALC_NUMBER	(360 * 100)

# if _USE_MATHS_HELPER
#  define SLIM3D_MATHS_COS(angle)	slim::MathsHelper::instance.getCosinus(angle)
#  define SLIM3D_MATHS_SIN(angle)	slim::MathsHelper::instance.getSinus(angle)
#  define SLIM3D_MATHS_TAN(angle)	slim::MathsHelper::instance.getTangeante(angle)
#  define SLIM3D_MATHS_ACOS(angle)	slim::MathsHelper::instance.getACosinus(angle)
#  define SLIM3D_MATHS_ASIN(angle)	slim::MathsHelper::instance.getASinus(angle)
#  define SLIM3D_MATHS_ATAN(angle)	slim::MathsHelper::instance.getATangeante(angle)
# else
#  define SLIM3D_MATHS_COS(angle)	slim::maths::lib::cos(angle)
#  define SLIM3D_MATHS_SIN(angle)	slim::maths::lib::sin(angle)
#  define SLIM3D_MATHS_TAN(angle)	slim::maths::lib::tan(angle)
#  define SLIM3D_MATHS_ACOS(angle)	slim::maths::lib::acos(angle)
#  define SLIM3D_MATHS_ASIN(angle)	slim::maths::lib::asin(angle)
#  define SLIM3D_MATHS_ATAN(angle)	slim::maths::lib::atan(angle)
# endif

namespace slim
{
namespace maths
{

template <typename T>
class		Helper : public core::Singleton
{
public:
    static Helper<T>	instance;

public:
    Helper();
    ~Helper();

public:
    void	init() override;
    void	destroy() override;

public:
    inline T	getCosinus(T angle) const;
    inline T	getSinus(T angle) const;
    inline T	getTangeante(T angle) const;

private:
    inline T	getAroundAngle(T angle) const;

private:
    T		m_coses[SLIM3D_MATHS_HELPER_PRECALC_NUMBER];
    T		m_sines[SLIM3D_MATHS_HELPER_PRECALC_NUMBER];
    T		m_tanes[SLIM3D_MATHS_HELPER_PRECALC_NUMBER];
};

}

typedef maths::Helper<float>	MathsHelper;

}

# include "Helper.hpp"

#endif // !SLIM3D_MATHS_HELPER_HH_
