//
// assert.hh for SLIM in /home/aracthor/programs/projects/SLIM/debug
// 
// Made by Aracthor
// 
// Started on  Mon Aug 31 23:19:45 2015 Aracthor
// Last Update Sun Sep  6 12:41:22 2015 Aracthor
//

#ifndef SLIM_DEBUG_ASSERT_HH_
# define SLIM_DEBUG_ASSERT_HH_

# include "slim/debug/AssertionException.hh"

# ifdef _DEBUG
#  define SLIM_DEBUG_ASSERT(condition) if (!(condition)) throw slim::debug::AssertionException(__FILE__, __func__, __LINE__);
# else
#  define SLIM_DEBUG_ASSERT(condition)
# endif // _DEBUG

#endif /* !SLIM_DEBUG_ASSERT_HH_ */
