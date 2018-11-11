find_package(Threads REQUIRED)

include_directories(./googletest/googletest/include)

add_executable(HashTableTest hash_table_test.cc)

target_link_libraries(HashTableTest gtest HashTables)

add_subdirectory(googletest)
