project("SLIM3D")

set(SRCS_FILES
  AssertionException.cpp
  console.cpp
  Exception.cpp
  Log.cpp
  LogManager.cpp
  LogStream.cpp
  SyscallException.cpp
  PARENT_SCOPE
  )

if (NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" AND
    NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(SRCS_FILES "${SRCS_FILES}"
  WindowsException.cpp
  PARENT_SCOPE
  )
