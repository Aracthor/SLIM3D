project("SLIM3D")

add_executable(chunks chunks.cpp)

target_link_libraries(chunks slim3d-core)
