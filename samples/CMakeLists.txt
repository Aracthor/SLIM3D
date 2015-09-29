project("SLIM3D")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/samples")
add_custom_target(make-samples-directory ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_subdirectory(hello_world_window)
add_subdirectory(cursor_image)
add_subdirectory(hello_world_shader)
