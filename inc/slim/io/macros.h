#ifndef SLIM_IO_MACCROS_H_
# define SLIM_IO_MACCROS_H_

# include "slim/core/system.h"

# if SLIM_CORE_SYSTEM_IS_UNIX || SLIM_CORE_SYSTEM_IS_APPLE
#  define SLIM_IO_SEPARATOR_CHAR	'/'
#  define SLIM_IO_ENDLINE_STR		"\n"
# elif SLIM_CORE_SYSTEM_IS_WINDOWS
#  define SLIM_IO_SEPARATOR_CHAR	'\\'
#  define SLIM_IO_ENDLINE_STR		"\r\n"
# else
#  error "Missing input/output maccros for this system."
# endif

#endif // !SLIM_IO_MACCROS_H_
