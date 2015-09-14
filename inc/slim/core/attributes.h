#ifndef SLIM_CORE_ATTRIBUTES_H_
# define SLIM_CORE_ATTRIBUTES_H_

# if defined(__GNUC__)
#  define SLIM_CORE_UNUSED __attribute__ ((unused))
#  define SLIM_CORE_PACKED __attribute__ ((packed))
# else
#  error "Need to define attributes for this compiler."
#  define SLIM_CORE_UNUSED
#  define SLIM_CORE_PACKED
# endif

#endif /* !SLIM_CORE_ATTRIBUTES_H_ */
