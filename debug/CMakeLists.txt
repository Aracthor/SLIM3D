project("SLIM3D")

set(DEBUG_SRCS_FILES
  AssertionException.cpp
  Dumper.cpp
  Exception.cpp
  Log.cpp
  LogManager.cpp
  SyscallException.cpp
  )

set(DEBUG_SRCS)
foreach (SRC_FILE ${DEBUG_SRCS_FILES})
  set(DEBUG_SRCS ${DEBUG_SRCS} srcs/${SRC_FILE})
endforeach()

add_library(slim3d-debug SHARED ${DEBUG_SRCS})

install (DIRECTORY inc/ DESTINATION include)
install (TARGETS slim3d-debug DESTINATION lib
  PERMISSIONS WORLD_EXECUTE WORLD_READ GROUP_EXECUTE GROUP_READ OWNER_EXECUTE OWNER_READ OWNER_WRITE)
