cmake_minimum_required(VERSION 3.15)
project(maith)

# enigine - find libraries
find_package(glfw3 REQUIRED)
find_package(glew REQUIRED)

add_executable(maith src/main.cpp)
# Define the path to the enigine directory
set(MAITH_DIR "${CMAKE_SOURCE_DIR}/..")


# enigine - link libraries
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} GLEW::GLEW)