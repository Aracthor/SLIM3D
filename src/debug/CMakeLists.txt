project("SLIM3D")

set(SRCS_FILES
  console.cpp
  exit.cpp
  Log.cpp
  LogManager.cpp
  LogStream.cpp
  )

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  list(APPEND SRCS_FILES WindowsException.cpp)
endif()

set(SRCS_FILES "${SRCS_FILES}" PARENT_SCOPE)
