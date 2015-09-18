project("SLIM3D")

set(SRCS
    test.cpp
    )

add_executable(win32-basic-test "${SRCS}")
target_link_libraries(win32-basic-test slim3d-graphics slim3d-core)
