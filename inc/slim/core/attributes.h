#ifndef SLIM_CORE_ATTRIBUTES_H_
# define SLIM_CORE_ATTRIBUTES_H_

# if defined(__GNUC__)
#  define SLIM_CORE_UNUSED __attribute__ ((unused))
# else
#  define SLIM_CORE_UNUSED
# endif

#endif /* !SLIM_CORE_ATTRIBUTES_H_ */
