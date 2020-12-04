cmake_minimum_required(VERSION 3.16)
project(5_server_msg LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp)
add_executable(main_dynamic main_dynamic.cpp)

add_library(operation SHARED operation.cpp)
set_target_properties(operation PROPERTIES VERSION ${PROJECT_VERSION} PUBLIC_HEADER library.h)


add_library(translation SHARED translation.cpp)
set_target_properties(translation PROPERTIES VERSION ${PROJECT_VERSION} PUBLIC_HEADER translation.h)

target_link_libraries(operation m)
target_link_libraries(translation m)

set(custom_targets)

list(APPEND custom_targets operation)
list(APPEND custom_targets translation)

target_link_libraries(main_dynamic ${CMAKE_DL_LIBS})
add_dependencies(main_dynamic operation translation)