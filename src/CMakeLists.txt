##
## CMakeLists.txt for SLIM3D in /home/aracthor/programs/projects/SLIM3D/src
## 
## Made by Aracthor
## 
## Started on  Fri Sep 11 21:14:40 2015 Aracthor
## Last Update Sat Sep 12 12:36:21 2015 Aracthor
##

project("SLIM3D")

set(CORE_DIRECTORIES
  core
  debug
  resources
  time
  )

set(CORE_SRCS)

function(collectSrcs directories SRCS)
  set(srcs)
  foreach(directory ${${directories}})
    add_subdirectory(${directory})
    foreach(src ${SRCS_FILES})
      set(srcs ${srcs} ${directory}/${src})
    endforeach()
  endforeach()
  set(${SRCS} ${srcs} PARENT_SCOPE)
endfunction(collectSrcs)

collectSrcs(CORE_DIRECTORIES CORE_SRCS)

set(CORE_SRCS ${CORE_SRCS} PARENT_SCOPE)
