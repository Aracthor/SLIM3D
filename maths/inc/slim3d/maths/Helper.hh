//
// Helper.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Fri Sep  4 16:06:31 2015 Aracthor
// Last Update Fri Sep  4 16:48:49 2015 Aracthor
//

#ifndef SLIM3D_MATHS_HELPER_HH_
# define SLIM3D_MATHS_HELPER_HH_

# include "slim3d/core/Singleton.hh"

# define SLIM3D_MATHS_HELPER_PRECALC_NUMBER	36000

namespace slim
{
namespace maths
{

template <typename T>
class	Helper : public core::Singleton
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
    T	getCosinus(T angle) const;
    T	getSinus(T angle) const;
    T	getTangeante(T angle) const;

private:
    T	m_coses[SLIM3D_MATHS_HELPER_PRECALC_NUMBER];
    T	m_sines[SLIM3D_MATHS_HELPER_PRECALC_NUMBER];
    T	m_tanes[SLIM3D_MATHS_HELPER_PRECALC_NUMBER];
};

}

typedef maths::Helper<float>	MathsHelper;

}

#endif // !SLIM3D_MATHS_HELPER_HH_
