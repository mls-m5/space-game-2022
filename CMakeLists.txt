
cmake_minimum_required(VERSION 3.24)
project(space)

add_subdirectory(lib/matengine)

add_executable(
    space
    src/main.cpp
)

target_link_libraries(
    space
    Mlse
)

file(
    COPY
    data
    DESTINATION
    .
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
