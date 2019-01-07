find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(GraphTest graph_test.cc)

target_link_libraries(GraphTest gtest Graph)

add_subdirectory(googletest)
