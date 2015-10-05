#ifndef SLIM_MATHS_HELPER_HH_
# define SLIM_MATHS_HELPER_HH_

# include "slim/core/Singleton.hh"
# include "slim/debug/assert.hh"
# include "slim/maths/lib.hh"

# define SLIM_MATHS_HELPER_PRECALC_NUMBER	(360 * 100)

# if _USE_MATHS_HELPER
#  define SLIM_MATHS_COS(angle)		slim::MathsHelper::instance.getCosinus(angle)
#  define SLIM_MATHS_SIN(angle)		slim::MathsHelper::instance.getSinus(angle)
#  define SLIM_MATHS_TAN(angle)		slim::MathsHelper::instance.getTangeante(angle)
#  define SLIM_MATHS_ACOS(angle)	slim::MathsHelper::instance.getACosinus(angle)
#  define SLIM_MATHS_ASIN(angle)	slim::MathsHelper::instance.getASinus(angle)
#  define SLIM_MATHS_ATAN(angle)	slim::MathsHelper::instance.getATangeante(angle)
# else
#  define SLIM_MATHS_COS(angle)		slim::maths::lib::cos(angle)
#  define SLIM_MATHS_SIN(angle)		slim::maths::lib::sin(angle)
#  define SLIM_MATHS_TAN(angle)		slim::maths::lib::tan(angle)
#  define SLIM_MATHS_ACOS(angle)	slim::maths::lib::acos(angle)
#  define SLIM_MATHS_ASIN(angle)	slim::maths::lib::asin(angle)
#  define SLIM_MATHS_ATAN(angle)	slim::maths::lib::atan(angle)
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
    bool	onInit() override;
    void	onDestroy() override;

public:
    inline T	getCosinus(T angle) const;
    inline T	getSinus(T angle) const;
    inline T	getTangeante(T angle) const;

private:
    inline T	getAroundAngle(T angle) const;

private:
    T		m_coses[SLIM_MATHS_HELPER_PRECALC_NUMBER];
    T		m_sines[SLIM_MATHS_HELPER_PRECALC_NUMBER];
    T		m_tanes[SLIM_MATHS_HELPER_PRECALC_NUMBER];
};

}

typedef maths::Helper<float>	MathsHelper;

}

# include "Helper.hpp"

#endif // !SLIM_MATHS_HELPER_HH_
