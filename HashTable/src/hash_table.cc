#include <hash_table.h>
#include <functional>

HashTable::HashTable(){}

HashTable::~HashTable(){}

void HashTable::Insert(std::string key, int32_t value){
  int32_t hash_result = std::hash<std::string>{}(key);
  int32_t index = std::abs(hash_result % kArraySize);

  array_[index].push_back(value);
}

void HashTable::Delete(std::string key, int32_t value){
  int32_t hash_result = std::hash<std::string>{}(key);
  int32_t index = std::abs(hash_result) % kArraySize;
  std::vector<int32_t> key_vector = array_[index];

  std::vector<int32_t>::iterator vector_iterator;

  // Iterate across vector
  for(vector_iterator = key_vector.begin() ;vector_iterator != key_vector.end(); vector_iterator++){
    if (*vector_iterator == value){
      if (key_vector.size() > 1){
        key_vector.erase(vector_iterator, vector_iterator + 1);
        array_[index] = key_vector;
        return;
      }
      else{
        key_vector.clear();
        array_[index] = key_vector;
        return;
      }
    }
  }
}

std::vector<int32_t> HashTable::Search(std::string key){
  int32_t hash_result = std::hash<std::string>{}(key);
  int32_t index = std::abs(hash_result) % kArraySize;

  return array_[index];
}
