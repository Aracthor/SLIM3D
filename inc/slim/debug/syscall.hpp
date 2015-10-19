#ifndef SLIM_DEBUG_SYSCALL_HPP_
# define SLIM_DEBUG_SYSCALL_HPP_

# include "slim/debug/exit.hpp"

# define SLIM_DEBUG_SYSCALL_CALL(syscall)	if (static_cast<int>(syscall) == -1) SLIM_DEBUG_EXIT("Syscall error")
# define SLIM_DEBUG_SYSCALL_CALL_PTR(syscall)	if ((syscall) == nullptr) SLIM_DEBUG_EXIT("Syscall error")

#endif // !SLIM_DEBUG_SYSCALL_HPP_
