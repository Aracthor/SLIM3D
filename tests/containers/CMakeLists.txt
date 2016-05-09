project("SLIM3D")

add_executable(map map.cpp)

target_link_libraries(map slim3d-core)
