project("SLIM3D")

set(SRCS
    CloseListener.cpp
    HelloWorldScene.cpp
    main.cpp
    )

add_executable(hello_world_scene ${SRCS})
target_link_libraries(hello_world_scene slim3d-graphics slim3d-core)
