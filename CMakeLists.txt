cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project("SLIM3D")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(warnings "/W4 /WX /EHsc")
endif()

if (NOT CONFIGURED_ONCE)
  set(CMAKE_CXX_FLAGS "${warnings}"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
  set(CMAKE_C_FLAGS   "${warnings}"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()



set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../bin)

set(DIRECTORIES
  )

set(INCLUDES)
foreach (DIRECTORY ${DIRECTORIES})
  set(INCLUDES ${INCLUDES} ${DIRECTORY}/inc)
endforeach()

include_directories(${INCLUDES})

foreach (DIRECTORY ${DIRECTORIES})
  add_subdirectory(${DIRECTORY})
endforeach()