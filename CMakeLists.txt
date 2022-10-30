
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
