/*
** system.h for SLIM3D in /home/aracthor/programs/projects/SLIM3D/core
** 
** Made by Aracthor
** 
** Started on  Tue Sep  1 17:36:54 2015 Aracthor
** Last Update Fri Sep 11 16:02:24 2015 Aracthor
*/

#ifndef SLIM3D_CORE_SYSTEM_H_
# define SLIM3D_CORE_SYSTEM_H_

# define SLIM3D_CORE_SYSTEM_LINUX	0x01
# define SLIM3D_CORE_SYSTEM_FREEBSD	0x02
# define SLIM3D_CORE_SYSTEM_MACOS	0x03
# define SLIM3D_CORE_SYSTEM_WINDOWS	0x08
# define SLIM3D_CORE_SYSTEM_ANDROID	0x10
# define SLIM3D_CORE_SYSTEM_IPHONE	0x11

# define IS_COMPUTER(SYSTEM)	((SYSTEM & 0xF0) == 0x00)
# define IS_PHONE(SYSTEM)	((SYSTEM & 0xF0) == 0x10)

/* Set everything to false by default, and then change the good one. */
# define SLIM3D_CORE_SYSTEM_IS_UNIX	0
# define SLIM3D_CORE_SYSTEM_IS_APPLE	0
# define SLIM3D_CORE_SYSTEM_IS_WINDOWS	0

/* Unix */
# if defined(__unix__)
#  undef SLIM3D_CORE_SYSTEM_IS_UNIX
#  define SLIM3D_CORE_SYSTEM_IS_UNIX	1
#  if defined(__linux__)
#   define SLIM3D_CORE_SYSTEM		SLIM3D_CORE_SYSTEM_LINUX
#  elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#   define SLIM3D_CORE_SYSTEM		SLIM3D_CORE_SYSTEM_FREEBSD
#  elif defined(__ANDROID__)
#   define SLIM3D_CORE_SYSTEM		SLIM3D_CORE_SYSTEM_ANDROID
#  else
#   error "Cannot recognize this Unix system."
#  endif

/* Apple */
# elif defined(__APPLE__) || defined(__MACH__)
#  undef SLIM3D_CORE_SYSTEM_IS_APPLE
#  define SLIM3D_CORE_SYSTEM_IS_APPLE	1
#  if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#   define SLIM3D_CORE_SYSTEM		SLIM3D_CORE_SYSTEM_IPHONE
#  elif TARGET_OS_MAC
#   define SLIM3D_CORE_SYSTEM		SLIM3D_CORE_SYSTEM_MACOS
#  else
#   error "Cannot recognize this Apple system."
#  endif

/* Windows */
# elif defined(__WIN32__)
#  undef SLIM3D_CORE_SYSTEM_IS_WINDOWS
#  define SLIM3D_CORE_SYSTEM_IS_WINDOWS	1
#  define SLIM3D_CORE_SYSTEM		SLIM3D_CORE_SYSTEM_WINDOWS

/* Unknown */
# else
#  error "Cannot recognize the system."
# endif

#endif /* !SLIM3D_CORE_SYSTEM_H_ */
