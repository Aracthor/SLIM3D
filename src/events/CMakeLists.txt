project("SLIM3D")

set(SRCS_FILES
  CloseListener.cpp
  Loop.cpp
  Manager.cpp
  )

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(SRCS_FILES
    ${SRCS_FILES}
    linux/KeyCodeConverter.cpp
    linux/MouseButtonConverter.cpp
    )
endif()

set(SRCS_FILES
  ${SRCS_FILES}
  PARENT_SCOPE
  )
