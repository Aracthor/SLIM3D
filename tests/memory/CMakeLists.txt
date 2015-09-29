project("SLIM3D")

set(SRCS
  heap_allocation.cpp
  )
  

add_executable(heap_allocation ${SRCS})
target_link_libraries(heap_allocation slim3d-core)
