/*
** system.h for SLIM3D in /home/aracthor/programs/projects/SLIM3D/core
** 
** Made by Aracthor
** 
** Started on  Tue Sep  1 17:36:54 2015 Aracthor
** Last Update Tue Sep  1 17:53:07 2015 Aracthor
*/

#ifndef SLIM3D_CORE_SYSTEM_H_
# define SLIM3D_CORE_SYSTEM_H_

# define SLIM3D_CORE_LINUX	0
# define SLIM3D_CORE_FREEBSD	1
# define SLIM3D_CORE_OSX	2
# define SLIM3D_CORE_WINDOWS	3

# if defined(__linux__)
#  define SLIM3D_CORE_SYSTEM	SLIM3D_CORE_LINUX
# elif defined(__FreeBSD__)
#  define SLIM3D_CORE_SYSTEM	SLIM3D_CORE_FREEBSD
# elif defined(__APPLE__) || defined(__MACH__)
#  define SLIM3D_CORE_SYSTEM	SLIM3D_CORE_OSX
# elif defined(__WIN32__)
#  define SLIM3D_CORE_SYSTEM	SLIM3D_CORE_WINDOWS
# else
#  error "Cannot recognize the system."
# endif

#endif /* !SLIM3D_CORE_SYSTEM_H_ */
