cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project("SLIM3D")
set (SLIM3D_VERSION_MAJOR 0)
set (SLIM3D_VERSION_MINOR 0)
set (SLIM3D_VERSION_PATCH 0)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings "-Wall -Wextra -Werror")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -D_DEBUG")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(warnings "/W4 /WX /EHsc")
endif()

if (NOT CONFIGURED_ONCE)
  set(CMAKE_CXX_FLAGS "${warnings}"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
  set(CMAKE_C_FLAGS   "${warnings}"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

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
set(CORE_SRCS)
set(GRAPHICS_SRCS)
add_subdirectory(${SRCS_DIR})

function(addSrcPath SRCS)
  set(srcs)
  foreach(file ${${SRCS}})
    set(srcs ${srcs} ${SRCS_DIR}/${file})
  endforeach()
  set(${SRCS} ${srcs} PARENT_SCOPE)
endfunction(addSrcPath)

addSrcPath(CORE_SRCS)
addSrcPath(GRAPHICS_SRCS)

add_library(slim3d-core SHARED ${CORE_SRCS})
add_library(slim3d-graphics SHARED ${GRAPHICS_SRCS})
target_link_libraries(slim3d-graphics slim3d-core)
target_link_libraries(slim3d-graphics glfw3)

if (NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" AND
    NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    foreach(source IN LISTS CORE_SRCS)
	get_filename_component(source_path "${source}" PATH)
	string(REPLACE "/" "\\" source_path_msvc "${source_path}")
	source_group("${source_path_msvc}" FILES "${source}")
    endforeach()
    foreach(source IN LISTS GRAPHICS_SRCS)
	get_filename_component(source_path "${source}" PATH)
	string(REPLACE "/" "\\" source_path_msvc "${source_path}")
	source_group("${source_path_msvc}" FILES "${source}")
    endforeach()
endif()

# TODO make link depending of plateform (currently for Linux only)
target_link_libraries(slim3d-graphics X11)
target_link_libraries(slim3d-graphics Xxf86vm)
target_link_libraries(slim3d-graphics pthread)
target_link_libraries(slim3d-graphics dl)
target_link_libraries(slim3d-graphics Xcursor)
target_link_libraries(slim3d-graphics Xrandr)
target_link_libraries(slim3d-graphics Xi)
target_link_libraries(slim3d-graphics Xinerama)

install (DIRECTORY inc/ DESTINATION include)
install (TARGETS slim3d-core DESTINATION lib)
install (TARGETS slim3d-graphics DESTINATION lib)
