cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

project("SLIM3D")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
   "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings "-Wall -Wextra -Werror")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -D_DEBUG")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  set(warnings "/W4 /WX /EHsc")
else()
  message("WARNING: There are no warning management for your compiler.")
endif()

if (NOT CONFIGURED_ONCE)
  set(CMAKE_CXX_FLAGS "${warnings}"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
  set(CMAKE_C_FLAGS   "${warnings}"
    CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
  message(STATUS "Your compiler (${CMAKE_CXX_COMPILER}) has no C++11 support. Please use a better C++ compiler.")
endif()


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../bin)

include_directories(inc/)

set(SRCS_DIR src)
set(SAMPLES_DIR samples)
set(TESTS_DIR tests)
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

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
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

add_library(slim3d-core "${CORE_SRCS}")
add_library(slim3d-graphics "${GRAPHICS_SRCS}")

target_link_libraries(slim3d-graphics slim3d-core)
target_link_libraries(slim3d-graphics glfw3)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  target_link_libraries(slim3d-graphics X11)
  target_link_libraries(slim3d-graphics Xxf86vm)
  target_link_libraries(slim3d-graphics pthread)
  target_link_libraries(slim3d-graphics dl)
  target_link_libraries(slim3d-graphics Xcursor)
  target_link_libraries(slim3d-graphics Xrandr)
  target_link_libraries(slim3d-graphics Xi)
  target_link_libraries(slim3d-graphics Xinerama)
elseif (MSVC)
  target_link_libraries(slim3d-graphics opengl32)
endif()

add_subdirectory(${SAMPLES_DIR})
add_subdirectory(${TESTS_DIR})

install (DIRECTORY inc/ DESTINATION include)
install (TARGETS slim3d-core DESTINATION lib)
install (TARGETS slim3d-graphics DESTINATION lib)
