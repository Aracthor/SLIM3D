project("SLIM3D")

add_executable(assignement assignement.cpp)
add_executable(vectors_operations vectors_operations.cpp)

target_link_libraries(assignement slim3d-core)
target_link_libraries(vectors_operations slim3d-core)
