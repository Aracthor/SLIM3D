project("SLIM3D")

set(DEBUG_SRCS_FILES
  AssertionException.cpp
  Exception.cpp
  Log.cpp
  LogManager.cpp
  )

set(DEBUG_SRCS)
foreach (SRC_FILE ${DEBUG_SRCS_FILES})
  set(DEBUG_SRCS ${DEBUG_SRCS} srcs/${SRC_FILE})
endforeach()

add_library(slim3d-debug SHARED ${DEBUG_SRCS})
