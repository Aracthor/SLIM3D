project("SLIM3D")

add_executable(smart_chunks smart_chunks.cpp)

target_link_libraries(smart_chunks slim3d-core)
