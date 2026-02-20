cmake_minimum_required(VERSION 3.20)

project(MyProject)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(prj.labs/complex)

target_link_libraries(main PRIVATE complex)
