#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

/***************************************************************************************************************************************************************
 * DESCRIPTION: A Binary tree is a hierarchical or a non-linear data structure. Every tree contains nodes, these nodes store data and have pointers to other
 *              nodes called leaves. We have a topmost node called the root node. From the root node we work are way down the tree with child nodes. This class
 *              contains a basic implementation of a binary tree. There are many different types of binary trees, this specific class implementation is a binary
 *              search tree.
 *
 **************************************************************************************************************************************************************/

struct Node {
  int32_t data;
  Node* left;
  Node* right;
};

class BinarySearchTree {
public:
  BinarySearchTree();
  ~BinarySearchTree();

  // Insert a node into the BST
  void Insert(int32_t value);

  // Insert a node into the BST recursively
  void InsertRecursively(int32_t value);

  // Search for a value in the BST. If the value is not in the
  // Tree it will return a nullptr
  Node* Search(int32_t value);

  // Same as Search(int32_t value) function above except it performs
  // the operation recursively
  Node* SearchRecursively(int32_t value);

  // Returns true if the value is in the BST is deleted
  bool Delete(int32_t value);

  // Print the BST in different order
  void PrintLevelOrder();
  void PrintPreorder();
  void PrintPostorder();
  void PrintInOrder();

private:
  void InsertRecursively(Node **root, int32_t value);
  Node* SearchRecursively(Node *root, int32_t value);
  void PreorderTraversal(Node *node);
  void InorderTraversal(Node *node);
  void PostorderTraversal(Node *node);

  Node* root_;
};

#endif //BINARYSEARCHTREE_H
