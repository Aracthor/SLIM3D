#ifndef SLIM_RESOURCES_MACCROS_H_
# define SLIM_RESOURCES_MACCROS_H_

# include "slim/core/system.h"

# if SLIM_CORE_SYSTEM_IS_UNIX || SLIM_CORE_SYSTEM_IS_APPLE
#  define SLIM_RESOURCES_SEPARATOR_CHAR	'/'
#  define SLIM_RESOURCES_ENDLINE_STR	"\n"
# elif SLIM_CORE_SYSTEM_IS_WINDOWS
#  define SLIM_RESOURCES_SEPARATOR_CHAR	'\\'
#  define SLIM_RESOURCES_ENDLINE_STR	"\r\n"
# else
#  error "Missing resources maccros for this system."
# endif

#endif // !SLIM_RESOURCES_MACCROS_H_
