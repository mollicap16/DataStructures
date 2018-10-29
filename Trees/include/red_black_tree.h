#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <iostream>

/***************************************************************************************************************************************************************
 * DESCRIPTION: A Red-Black tree is a self-balancing binary search tree. This ensures that the hight of the tree will be bounded by O(N), where N is the number
 *              of nodes. The self-balancing property is maintained by coloring each nodes of the tree as either red or black.
 *
 * NOTE: For more informations about recoloring, rotations, insertion cases and deletions cases refer to the Data Structure Notes in the docs folder.
 *
 **************************************************************************************************************************************************************/

enum class NodeColor {kRed, kBlack, kDoubleBlack, kNull};

struct RedBlackNode {
  int32_t data;
  NodeColor color;
  bool null_flag;
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
  bool Remove(int32_t value); // Returns false if node is not in the tree
  bool IsEmpty();

  // Print tree
  void PrintLevelOrder();
  void PrintPreorder();
  void PrintInorder();
  void PrintPostorder();

private:
  RedBlackNode* root_;

  void BstInsert(RedBlackNode* &root, RedBlackNode* &node);
  void FixInsertViolations(RedBlackNode* &node);
  void RotateLeftLeft(RedBlackNode* &parent, RedBlackNode* &grandparent);
  void RotateRightRight(RedBlackNode* &parent, RedBlackNode* &grandparent);
  void RotateLeftRight(RedBlackNode* &child, RedBlackNode* &parent, RedBlackNode* &grandparent);
  void RotateRightLeft(RedBlackNode* &child, RedBlackNode* &parent, RedBlackNode* &grandparent);
  void RemoveCase1(RedBlackNode* &inorder_predecessor, RedBlackNode* &delete_node);
  void RemoveCase2(RedBlackNode* &inorder_predecessor, RedBlackNode* &delete_node);
  void RemoveCase3_1(RedBlackNode* &double_black_node);
  void RemoveCase3_2(RedBlackNode* &double_black_node, RedBlackNode* &double_black_parent, RedBlackNode* &double_black_sibling);
  void RemoveCase3_3(RedBlackNode* &double_black_node, RedBlackNode* &double_black_parent, RedBlackNode* &double_black_sibling);
  void RemoveCase3_4(RedBlackNode* &double_black_node, RedBlackNode* &double_black_parent, RedBlackNode* &double_black_sibling);
  void RemoveCase3_5(RedBlackNode* &double_black_node, RedBlackNode* &double_black_parent, RedBlackNode* &double_black_sibling);
  void RemoveCase3_6(RedBlackNode* &double_black_node, RedBlackNode* &double_black_parent, RedBlackNode* &double_black_sibling);
  void RotateLeft(RedBlackNode* &parent_node);
  void RotateRight(RedBlackNode* &parent_node);
  RedBlackNode* FindMin(RedBlackNode* &node);
  RedBlackNode* FindMax(RedBlackNode* &node);
  RedBlackNode* FindSibling(RedBlackNode* &node);
  NodeColor OuterChildColor(RedBlackNode* &parent, RedBlackNode* &child_node);
  NodeColor InnerChildColor(RedBlackNode* &parent, RedBlackNode* &child_node);

  void PreorderTraversal(RedBlackNode* node);
  void InorderTraversal(RedBlackNode* node);
  void PostorderTraversal(RedBlackNode* node);
};

#endif //REDBLACKTREE_H
