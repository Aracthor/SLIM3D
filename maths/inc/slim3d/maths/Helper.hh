//
// Helper.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Fri Sep  4 16:06:31 2015 Aracthor
// Last Update Sat Sep  5 12:41:52 2015 Aracthor
//

#ifndef SLIM3D_MATHS_HELPER_HH_
# define SLIM3D_MATHS_HELPER_HH_

# include "slim3d/core/Singleton.hh"
# include "slim3d/debug/assert.hh"
# include "slim3d/maths/lib.hh"

# define SLIM3D_MATHS_HELPER_PRECALC_NUMBER	36000

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

# include "Helper.hpp"

}

typedef maths::Helper<float>	MathsHelper;

}

#endif // !SLIM3D_MATHS_HELPER_HH_
