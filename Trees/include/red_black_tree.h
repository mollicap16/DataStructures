#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>

/***************************************************************************************************************************************************************
 * DESCRIPTION: A Red-Black tree is a self-balancing binary search tree. This ensures that the hight of the tree will be bounded by O(N), where N is the number
 *              of nodes. The self-balancing property is maintained by coloring each nodes of the tree as either red or black.
 *
 **************************************************************************************************************************************************************/

enum class NodeColor {kRed, kBlack};

struct RedBlackNode {
  int32_t data;
  NodeColor color;
  RedBlackNode* parent;
  RedBlackNode* left;
  RedBlackNode* right;
};

class RedBlackTree {
public:
  RedBlackTree();
  ~RedBlackTree();

  // Returns nullptr if value is not found
  RedBlackNode* Search(int32_t value);
  void Insert(int32_t value);
  bool Remove(int32_t value);

  // Print tree
  void PrintLevelOrder();
  void PrintPreorder();
  void PrintInorder();
  void PrintPostorder();

private:
  RedBlackNode* root_;

  void InsertBst(RedBlackNode* &root, RedBlackNode* &node);
  void FixInsertViolations(RedBlackNode* &node);
  void RotateLeftLeft(RedBlackNode* &/*child*/, RedBlackNode* &parent, RedBlackNode* &grandparent);
  void RotateRightRight(RedBlackNode* &child, RedBlackNode* &parent, RedBlackNode* &grandparent);
  void RotateLeftRight(RedBlackNode* &child, RedBlackNode* &parent, RedBlackNode* &grandparent);
  void RotateRightLeft(RedBlackNode* &child, RedBlackNode* &parent, RedBlackNode* &grandparent);
};

#endif //REDBLACKTREE_H
