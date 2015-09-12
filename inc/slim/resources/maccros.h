/*
** maccros.h for SLIM in /home/aracthor/programs/projects/SLIM/resources
** 
** Made by Aracthor
** 
** Started on  Thu Sep  3 21:16:38 2015 Aracthor
** Last Update Sat Sep 12 13:56:40 2015 Aracthor
*/

#ifndef SLIM_RESOURCES_MACCROS_H_
# define SLIM_RESOURCES_MACCROS_H_

# include "slim/core/system.h"

# if SLIM_CORE_SYSTEM_IS_UNIX || SLIM_CORE_SYSTEM_IS_APPLE
#  define SLIM_RESOURCES_SEPARATOR_CHAR	'/'
# elif SLIM_CORE_SYSTEM_IS_WINDOWS
#  define SLIM_RESOURCES_SEPARATOR_CHAR	'\\'
# else
#  error "Missing resources maccros for this system."
# endif

#endif // !SLIM_RESOURCES_MACCROS_H_
