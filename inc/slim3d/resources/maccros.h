/*
** maccros.h for SLIM3D in /home/aracthor/programs/projects/SLIM3D/resources
** 
** Made by Aracthor
** 
** Started on  Thu Sep  3 21:16:38 2015 Aracthor
** Last Update Fri Sep 11 16:04:51 2015 Aracthor
*/

#ifndef SLIM3D_RESOURCES_MACCROS_H_
# define SLIM3D_RESOURCES_MACCROS_H_

# include "slim3d/core/system.h"

# if SLIM3D_CORE_SYSTEM_IS_UNIX || SLIM3D_CORE_SYSTEM_IS_APPLE
#  define SLIM3D_RESOURCES_SEPARATOR_CHAR	'/'
# elif SLIM3D_CORE_SYSTEM_IS_WINDOWS
#  define SLIM3D_RESOURCES_SEPARATOR_CHAR	'\\'
# else
#  error "Missing resources maccros for this system."
# endif

#endif // !SLIM3D_RESOURCES_MACCROS_H_
