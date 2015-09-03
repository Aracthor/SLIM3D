/*
** maccros.h for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
** 
** Made by Aracthor
** 
** Started on  Thu Sep  3 21:16:38 2015 Aracthor
** Last Update Thu Sep  3 21:20:13 2015 Aracthor
*/

#ifndef SLIM3D_RESOURCES_MACCROS_H_
# define SLIM3D_RESOURCES_MACCROS_H_

# include "slim3d/core/system.h"

# if IS_UNIX(SLIM3D_CORE_SYSTEM)
#  define SLIM3D_RESOURCES_SEPARATOR_CHAR	'/'
# elif SLIM3D_CORE_SYSTEM == SLIM3D_CORE_WINDOWS
#  define SLIM3D_RESOURCES_SEPARATOR_CHAR	'\\'
# else
#  error "Missing resources maccros for this system."
# endif

#endif // !SLIM3D_RESOURCES_MACCROS_H_
