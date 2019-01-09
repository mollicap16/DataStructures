find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(SortingTest sorting_test.cc)

target_link_libraries(SortingTest gtest Sorting)

add_subdirectory(googletest)
