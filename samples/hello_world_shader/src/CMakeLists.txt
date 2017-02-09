project("SLIM3D")

set(SRCS
    HelloWorldShader.cpp
    main.cpp
    )

add_executable(hello_world_shader ${SRCS})
target_link_libraries(hello_world_shader slim3d-graphics slim3d-core)
