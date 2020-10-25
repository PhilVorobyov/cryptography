cmake_minimum_required(VERSION 3.17)

project(cryptography)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES Main.cpp)

add_executable(cryptography ${SOURCE_FILES})

include_directories(cryptography "/usr/local/Cellar/gmp/6.1.2_2/include")
include_directories(cryptography "/usr/local/lib/")

target_link_libraries(cryptography /usr/local/lib/libgmp.a)