
add_executable(zernike3d main.cpp)
target_link_libraries(zernike3d 3DZM)

add_executable(sphere_test sphere_test.cpp)
target_link_libraries(sphere_test 3DZM)
