project("SLIM3D")

set(CORE_SRCS_FILES
  SingletonsManager.cpp
  )

set(CORE_SRCS)
foreach (SRC_FILE ${CORE_SRCS_FILES})
  set(CORE_SRCS ${CORE_SRCS} srcs/${SRC_FILE})
endforeach()

add_library(slim3d-core SHARED ${CORE_SRCS})
