#ifndef SLIM_DEBUG_ASSERT_HH_
# define SLIM_DEBUG_ASSERT_HH_

# include "slim/debug/AssertionException.hh"

# ifdef _DEBUG
#  define SLIM_DEBUG_ASSERT(condition) if (!(condition)) throw slim::debug::AssertionException(__FILE__, __func__, __LINE__);
# else
#  define SLIM_DEBUG_ASSERT(condition)
# endif // _DEBUG

# define SLIM_DEBUG_REINTERPRET_CAST(type, dest, src)	SLIM_DEBUG_ASSERT(dynamic_cast<type>(src) != nullptr); dest = reinterpret_cast<type>(src)

#endif /* !SLIM_DEBUG_ASSERT_HH_ */
