project("LinkedList")
cmake_minimum_required(VERSION 2.8)

set(CMAKE_INCLUDE_CURRENT_DIR ON) # Find includes in corresponding build directories
set(CMAKE_AUTOMOC ON) # Instruct CMake to run moc automatically when needed.

include_directories("include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic -pthread -std=c++11")

set(CMAKE_BUILD_TYPE Debug)

file(GLOB INC "include/*.h")
file(GLOB SRC "src/*.c*")

add_executable(${PROJECT_NAME} ${INC} ${SRC})
