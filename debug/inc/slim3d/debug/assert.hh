//
// assert.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:19:45 2015 Aracthor
// Last Update Sun Sep  6 12:34:39 2015 Aracthor
//

#ifndef SLIM3D_DEBUG_ASSERT_HH_
# define SLIM3D_DEBUG_ASSERT_HH_

# include "slim3d/debug/AssertionException.hh"

# ifdef _DEBUG
#  define SLIM3D_DEBUG_ASSERT(condition) if (!(condition)) throw AssertionException(__FILE__, __func__, __LINE__);
# else
#  define SLIM3D_DEBUG_ASSERT(condition)
# endif // _DEBUG

#endif /* !SLIM3D_DEBUG_ASSERT_HH_ */
