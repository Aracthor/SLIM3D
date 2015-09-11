##
## CMakeLists.txt for SLIM3D in /home/aracthor/programs/projects/SLIM3D/src
## 
## Made by Aracthor
## 
## Started on  Fri Sep 11 21:14:40 2015 Aracthor
## Last Update Fri Sep 11 21:36:42 2015 Aracthor
##

set(DIRECTORIES
  core
  debug
  resources
  time
  )

set(SRCS_FILES)
foreach(DIRECTORY ${DIRECTORIES})
  add_subdirectory(${DIRECTORY})
  foreach(SRC_DIR_FILE ${SRCS_DIR_FILES})
    set(SRCS_FILES ${SRCS_FILES} ${DIRECTORY}/${SRC_DIR_FILE})
  endforeach()
endforeach()

set(SRCS_FILES ${SRCS_FILES} PARENT_SCOPE)
