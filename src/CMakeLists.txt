project("SLIM3D")

set(CORE_SRCS)
set(CORE_DIRECTORIES
  assets
  core
  debug
  io
  memory
  time
  )

set(GRAPHICS_SRCS)
set(GRAPHICS_DIRECTORIES
  engine
  events
  graphics
  shader
  window
  )

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
collectSrcs(GRAPHICS_DIRECTORIES GRAPHICS_SRCS)

set(CORE_SRCS ${CORE_SRCS} PARENT_SCOPE)
set(GRAPHICS_SRCS ${GRAPHICS_SRCS} PARENT_SCOPE)
