project("SLIM3D")

set(SRCS
    HelloWorldWindow.cpp
    main.cpp
    )

add_executable(hello_world_window ${SRCS})
target_link_libraries(hello_world_window slim3d-graphics slim3d-core)
