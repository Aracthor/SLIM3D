project("SLIM3D")

set(SRCS
    CloseListener.cpp
    CursorImageEngine.cpp
    main.cpp
    )

add_executable(cursor_image ${SRCS})
target_link_libraries(cursor_image slim3d-graphics slim3d-core)
