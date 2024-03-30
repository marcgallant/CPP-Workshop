cmake_minimum_required(VERSION 3.21.2)
project(hello_yaka)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-Wall -Wextra -Werror -pedantic -std=c++20 -Wold-style-cast)

add_subdirectory(libyaka)

add_executable(hello_yaka libyaka/src/yaka.cc src/main.cc)

target_link_libraries(hello_yaka PUBLIC yaka)

target_include_directories(hello_yaka PUBLIC
                          "yaka"
                          "libyaka/include"
                          )
