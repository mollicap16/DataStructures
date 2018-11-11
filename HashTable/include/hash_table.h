#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>

/***************************************************************************************************************************************************************
 * DESCRIPTION: A HashTable is a data structure used to map a specified key to a value (Key/Value) pair. The storage medium is an array, where the key is mapped
 *              to a specified index of the array through the use of a hash function.
 *
 * IMPLEMENTATION: In this implementation we will be using separate chaining to handle any collisions.
 *
 **************************************************************************************************************************************************************/

static const int32_t kArraySize = 599; // Prime number (to help reduce number of collisions)

class HashTable {
public:
  HashTable();
  ~HashTable();

  void Insert(std::string key, int32_t value);
  void Delete(std::string key, int32_t value);
  std::vector<int32_t> Search(std::string key);
  std::vector<int32_t>* GetTable(){return array_;}

private:
  std::vector<int32_t> array_[kArraySize];  // The vector acts as the linked list to handle collisions
};

#endif //HASHTABLE
