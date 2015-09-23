#ifndef SLIM_CORE_SYSTEM_H_
# define SLIM_CORE_SYSTEM_H_

# define SLIM_CORE_SYSTEM_LINUX		0x01
# define SLIM_CORE_SYSTEM_FREEBSD	0x02
# define SLIM_CORE_SYSTEM_MACOS		0x03
# define SLIM_CORE_SYSTEM_WINDOWS	0x08
# define SLIM_CORE_SYSTEM_ANDROID	0x10
# define SLIM_CORE_SYSTEM_IPHONE	0x11

# define SLIM_CORE_IS_COMPUTER(SYSTEM)	((SYSTEM & 0xF0) == 0x00)
# define SLIM_CORE_IS_PHONE(SYSTEM)     ((SYSTEM & 0xF0) == 0x10)

/* Set everything to false by default, and then change the good one. */
# define SLIM_CORE_SYSTEM_IS_UNIX	0
# define SLIM_CORE_SYSTEM_IS_APPLE	0
# define SLIM_CORE_SYSTEM_IS_WINDOWS	0

/* Unix */
# if defined(__unix__)
#  undef SLIM_CORE_SYSTEM_IS_UNIX
#  define SLIM_CORE_SYSTEM_IS_UNIX	1
#  if defined(__linux__)
#   define SLIM_CORE_SYSTEM		SLIM_CORE_SYSTEM_LINUX
#  elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#   define SLIM_CORE_SYSTEM		SLIM_CORE_SYSTEM_FREEBSD
#  elif defined(__ANDROID__)
#   define SLIM_CORE_SYSTEM		SLIM_CORE_SYSTEM_ANDROID
#  else
#   error "Cannot recognize this Unix system."
#  endif

/* Apple */
# elif defined(__APPLE__) || defined(__MACH__)
#  undef SLIM_CORE_SYSTEM_IS_APPLE
#  define SLIM_CORE_SYSTEM_IS_APPLE	1
#  if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#   define SLIM_CORE_SYSTEM		SLIM_CORE_SYSTEM_IPHONE
#  elif TARGET_OS_MAC
#   define SLIM_CORE_SYSTEM		SLIM_CORE_SYSTEM_MACOS
#  else
#   error "Cannot recognize this Apple system."
#  endif

/* Windows */
# elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__)
#  undef SLIM_CORE_SYSTEM_IS_WINDOWS
#  define SLIM_CORE_SYSTEM_IS_WINDOWS	1
#  define SLIM_CORE_SYSTEM		SLIM_CORE_SYSTEM_WINDOWS

/* Unknown */
# else
#  error "Cannot recognize the system."
# endif

#endif /* !SLIM_CORE_SYSTEM_H_ */
