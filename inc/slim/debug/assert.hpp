#ifndef SLIM_DEBUG_ASSERT_HH_
# define SLIM_DEBUG_ASSERT_HH_

# include "slim/debug/exit.hpp"

# ifdef _DEBUG
#  define SLIM_DEBUG_ASSERT(condition) if (!(condition)) SLIM_DEBUG_EXIT("Assertion error");
# else
#  define SLIM_DEBUG_ASSERT(condition)
# endif

# define SLIM_DEBUG_REINTERPRET_CAST(type, dest, src)	SLIM_DEBUG_ASSERT(dynamic_cast<type>(src) != nullptr); dest = reinterpret_cast<type>(src)

#endif /* !SLIM_DEBUG_ASSERT_HH_ */
