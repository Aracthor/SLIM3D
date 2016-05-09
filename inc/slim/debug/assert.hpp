#ifndef SLIM_DEBUG_ASSERT_HPP_
# define SLIM_DEBUG_ASSERT_HPP_

# include <typeinfo>

# include "slim/debug/exit.hpp"

# ifdef _DEBUG
#  define SLIM_DEBUG_ASSERT(condition) if(!(condition)) SLIM_DEBUG_EXIT("Assertion error ", typeid(*this).name());
#  define SLIM_DEBUG_STATIC_ASSERT(condition) if(!(condition)) SLIM_DEBUG_EXIT("Assertion error");
# else
#  define SLIM_DEBUG_ASSERT(condition)
#  define SLIM_DEBUG_STATIC_ASSERT(condition)
# endif

# define SLIM_DEBUG_REINTERPRET_CAST(type, dest, src)	SLIM_DEBUG_ASSERT(dynamic_cast<type>(src) != nullptr); dest = reinterpret_cast<type>(src)

#endif /* !SLIM_DEBUG_ASSERT_HPP_ */
