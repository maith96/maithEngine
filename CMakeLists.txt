cmake_minimum_required(VERSION 3.15)
project(maith)

# enigine - find libraries
find_package(glfw3 REQUIRED)
find_package(glew REQUIRED)
find_package(glm REQUIRED)

# Add all .cpp files in the src directory and its subdirectories
file(GLOB_RECURSE CPP_SOURCES ${ENIGINE_DIR}/src/*.cpp src/*.cpp)

# Add all .h files in the src directory and its subdirectories
file(GLOB_RECURSE HEADER_FILES ${ENIGINE_DIR}/src/*.h src/*.h)


add_executable(maith src/main.cpp)
# Define the path to the enigine directory
set(MAITH_DIR "${CMAKE_SOURCE_DIR}/..")


#copy shaders
file(COPY src/shaders DESTINATION ${CMAKE_BINARY_DIR}/)

#  - link libraries
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} GLEW::GLEW)
target_link_libraries(${PROJECT_NAME} glm::glm)
