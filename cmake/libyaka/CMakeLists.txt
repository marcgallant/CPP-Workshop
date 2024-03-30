set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-Wall -Wextra -Werror -pedantic -std=c++20 -Wold-style-cast)

add_library(yaka SHARED src/yaka.cc)

target_include_directories(yaka PUBLIC
                          "include"
                          )
