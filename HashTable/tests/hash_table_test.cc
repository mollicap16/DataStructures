#include <iostream>
#include <gtest/gtest.h>
#include <hash_table.h>
#include <functional>

TEST(HashTableTest, InsertTest1){
  HashTable id_lookup_table;
  id_lookup_table.Insert("Bob", 1);
  id_lookup_table.Insert("John", 20);
  id_lookup_table.Insert("JOHN", 150);
  id_lookup_table.Insert("George", 45);
  id_lookup_table.Insert("Georgy", 30);

  std::vector<int32_t>* hash_table = id_lookup_table.GetTable();
  int32_t hash_result = std::hash<std::string>{}("George");
  int32_t hash_index = abs(hash_result) % kArraySize;
//  std::cout << "Hash Index = " << hash_index << std::endl;

  ASSERT_EQ(hash_table[hash_index][0], 45);

  hash_result = std::hash<std::string>{}("Georgy");
  hash_index = abs(hash_result) % kArraySize;
//  std::cout << "Hash Index = " << hash_index << std::endl;

  ASSERT_EQ(hash_table[hash_index][0], 30);

  hash_result = std::hash<std::string>{}("Bob");
  hash_index = abs(hash_result) % kArraySize;

  ASSERT_EQ(hash_table[hash_index][0], 1);

  hash_result = std::hash<std::string>{}("John");
  hash_index = abs(hash_result) % kArraySize;

//  std::cout << "Hash Index = " << hash_index << std::endl;

  ASSERT_EQ(hash_table[hash_index][0], 20);

  hash_result = std::hash<std::string>{}("JOHN");
  hash_index = abs(hash_result) % kArraySize;

//  std::cout << "Hash Index = " << hash_index << std::endl;

  ASSERT_EQ(hash_table[hash_index][0], 150);
}

// Delete Test
TEST(HashTableTest, DeleteTest1){
  HashTable id_lookup_table;

  id_lookup_table.Insert("Nick", 20);
  id_lookup_table.Insert("Dylan", 36);
  id_lookup_table.Insert("Jet", 50);

  std::vector<int32_t> search_vector = id_lookup_table.Search("Jet");

  ASSERT_EQ(search_vector[0], 50);
  id_lookup_table.Delete("Jet", 45);
  ASSERT_EQ(search_vector[0], 50);

  id_lookup_table.Delete("Jet", 50);
  search_vector = id_lookup_table.Search("Jet");
  ASSERT_EQ(search_vector.size(), 0);

  id_lookup_table.Delete("Pete", 10);
  search_vector = id_lookup_table.Search("Pete");
  ASSERT_EQ(search_vector.size(), 0);
}

// Collision Test
TEST(HashTableTest, CollisionTest1){
  HashTable id_lookup_table;
  id_lookup_table.Insert("Frank", 1234);
  id_lookup_table.Insert("Frank", 12);
  id_lookup_table.Insert("Frank", 123);

  id_lookup_table.Delete("Frank", 12);
  std::vector<int32_t> search_vector = id_lookup_table.Search("Frank");

  ASSERT_EQ(search_vector[0], 1234);
  ASSERT_EQ(search_vector[1], 123);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
