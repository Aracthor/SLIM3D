##
## CMakeLists.txt for SLIM3D in /home/aracthor/programs/projects/SLIM3D
## 
## Made by Aracthor
## 
## Started on  Fri Sep 11 21:09:49 2015 Aracthor
## Last Update Fri Sep 11 21:35:19 2015 Aracthor
##

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project("SLIM3D")
set (SLIM3D_VERSION_MAJOR 0)
set (SLIM3D_VERSION_MINOR 0)
set (SLIM3D_VERSION_PATCH 1)

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

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a better C++ compiler.")
endif()


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../bin)

include_directories(inc/)

set(SRCS_DIR src)
set(SRCS_FILES)
add_subdirectory(${SRCS_DIR})

set(SRCS)
foreach(SRC_FILE ${SRCS_FILES})
  set(SRCS ${SRCS} ${SRCS_DIR}/${SRC_FILE})
endforeach()

message(${SRCS})
add_library(slim3d SHARED ${SRCS})

install (DIRECTORY inc/ DESTINATION include)
install (TARGETS slim3d DESTINATION lib
  PERMISSIONS WORLD_EXECUTE WORLD_READ GROUP_EXECUTE GROUP_READ OWNER_EXECUTE OWNER_READ OWNER_WRITE)
