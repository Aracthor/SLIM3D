project("SLIM3D")

set(SRCS
    Cube.cpp
    main.cpp
    )

add_executable(cube ${SRCS})
target_link_libraries(cube slim3d-graphics slim3d-core)
