project("SLIM3D")

set(RESOURCES_SRCS_FILES
  BufferedFile.cpp
  BufferedReadingFile.cpp
  BufferedWritingFile.cpp
  File.cpp
  FileException.cpp
  UnbufferedFile.cpp
  UnbufferedReadingFile.cpp
  UnbufferedWritingFile.cpp
  )

set(RESOURCES_SRCS)
foreach (SRC_FILE ${RESOURCES_SRCS_FILES})
  set(RESOURCES_SRCS ${RESOURCES_SRCS} srcs/${SRC_FILE})
endforeach()

add_library(slim3d-resources SHARED ${RESOURCES_SRCS})

install (DIRECTORY inc/ DESTINATION include)
install (TARGETS slim3d-resources DESTINATION lib
  PERMISSIONS WORLD_EXECUTE WORLD_READ GROUP_EXECUTE GROUP_READ OWNER_EXECUTE OWNER_READ OWNER_WRITE)
