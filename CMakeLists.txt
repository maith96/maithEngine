cmake_minimum_required(VERSION 3.15)
project(maith)

add_executable(maith src/main.cpp)
# Define the path to the enigine directory
set(MAITH_DIR "${CMAKE_SOURCE_DIR}/..")