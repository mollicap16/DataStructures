#include <iostream>
#include <gtest/gtest.h>
#include <BinarySearchTree.h>

TEST(BinarSearchTreeTest, TestSearchNull){
  BinarySearchTree tree;
  Node* return_node = new Node();
  return_node = tree.Search(0);

  ASSERT_EQ(return_node, nullptr);
}

TEST(BinarSearchTreeTest, SingleItemSearchFail){
  BinarySearchTree tree;
  Node* return_node = new Node();

  tree.Insert(3);
  return_node = tree.Search(1);

  ASSERT_EQ(return_node, nullptr);
}

TEST(BinarySearchTreeTest, MultipleItemSearchPass){
  BinarySearchTree tree;
  Node* return_node = new Node();

  tree.Insert(3);
  tree.Insert(1);
  tree.Insert(5);

  return_node = tree.Search(3);
  ASSERT_EQ(return_node->left->data, 1);
  ASSERT_EQ(return_node->right->data, 5);
}

TEST(BinarySearchTreeTest, MultipleItemsMultipleSearches){
  BinarySearchTree tree;
  Node* return_node = new Node();

  tree.Insert(5);
  tree.Insert(3);
  tree.Insert(4);
  tree.Insert(6);
  tree.Insert(1);

  return_node = tree.Search(5);
  ASSERT_EQ(return_node->left->data, 3);
  ASSERT_EQ(return_node->right->data, 6);
  ASSERT_EQ(return_node->left->right->data, 4);
  ASSERT_EQ(return_node->left->left->data, 1);

  return_node = tree.Search(3);
  ASSERT_EQ(return_node->data, 3);
  ASSERT_EQ(return_node->left->data, 1);
  ASSERT_EQ(return_node->right->data, 4);

  return_node = tree.Search(6);
  ASSERT_EQ(return_node->data, 6);
  ASSERT_EQ(return_node->left, nullptr);
  ASSERT_EQ(return_node->right, nullptr);
}

TEST(BinarySearchTreeTest, MultipleItemsMultipleSearchesRecursive){
  BinarySearchTree tree;
  Node* return_node = new Node();

  tree.Insert(5);
  tree.Insert(3);
  tree.Insert(4);
  tree.Insert(6);
  tree.Insert(1);

  return_node = tree.SearchRecursively(5);
  ASSERT_EQ(return_node->left->data, 3);
  ASSERT_EQ(return_node->right->data, 6);
  ASSERT_EQ(return_node->left->right->data, 4);
  ASSERT_EQ(return_node->left->left->data, 1);

  return_node = tree.SearchRecursively(3);
  ASSERT_EQ(return_node->data, 3);
  ASSERT_EQ(return_node->left->data, 1);
  ASSERT_EQ(return_node->right->data, 4);

  return_node = tree.SearchRecursively(6);
  ASSERT_EQ(return_node->data, 6);
  ASSERT_EQ(return_node->left, nullptr);
  ASSERT_EQ(return_node->right, nullptr);

  return_node = tree.SearchRecursively(20);
  ASSERT_EQ(return_node, nullptr);
}


TEST(BinarySearchTreeTest, RecursiveInsertTest){
  BinarySearchTree tree;
  Node* return_node = new Node();

  tree.InsertRecursively(5);
  tree.InsertRecursively(3);
  tree.InsertRecursively(4);
  tree.InsertRecursively(6);
  tree.InsertRecursively(1);

  return_node = tree.SearchRecursively(5);
  ASSERT_EQ(return_node->data, 5);
  ASSERT_EQ(return_node->left->data, 3);
  ASSERT_EQ(return_node->right->data, 6);
  ASSERT_EQ(return_node->left->right->data, 4);
  ASSERT_EQ(return_node->left->left->data, 1);

  return_node = tree.SearchRecursively(3);
  ASSERT_EQ(return_node->data, 3);
  ASSERT_EQ(return_node->left->data, 1);
  ASSERT_EQ(return_node->right->data, 4);

  return_node = tree.SearchRecursively(6);
  ASSERT_EQ(return_node->data, 6);
  ASSERT_EQ(return_node->left, nullptr);
  ASSERT_EQ(return_node->right, nullptr);

  return_node = tree.SearchRecursively(20);
  ASSERT_EQ(return_node, nullptr);
}

TEST(BinarySearchTreeTest, PrintPreOrderTree){
  BinarySearchTree tree;

  tree.Insert(5);
  tree.Insert(3);
  tree.Insert(4);
  tree.Insert(6);
  tree.Insert(1);
  tree.Insert(10);
  tree.Insert(11);
  tree.Insert(8);

  tree.PrintPreorder();
}

TEST(BinarySearchTreeTest, PrintInOrderTree){
  BinarySearchTree tree;

  tree.Insert(5);
  tree.Insert(3);
  tree.Insert(4);
  tree.Insert(6);
  tree.Insert(1);
  tree.Insert(10);
  tree.Insert(11);
  tree.Insert(8);

  tree.PrintInorder();
}

TEST(BinarySearchTreeTest, PrintPostOrderTree){
  BinarySearchTree tree;

  tree.Insert(5);
  tree.Insert(3);
  tree.Insert(4);
  tree.Insert(6);
  tree.Insert(1);
  tree.Insert(10);
  tree.Insert(11);
  tree.Insert(8);

  tree.PrintPostorder();
}

TEST(BinarSearchTreeTest, PrintLevelOrderTree){
  BinarySearchTree tree;

  tree.Insert(5);
  tree.Insert(3);
  tree.Insert(4);
  tree.Insert(6);
  tree.Insert(1);
  tree.Insert(10);
  tree.Insert(11);
  tree.Insert(8);

  tree.PrintLevelOrder();
  std::cout << std::endl;
  tree.PrintLevelOrder();
}

TEST(BinarySearchTreeTest, DeleteNodeWithNoChildren){
  BinarySearchTree tree;

  tree.Insert(5);

  tree.PrintLevelOrder();
  ASSERT_EQ(tree.Delete(5), true);
  tree.PrintLevelOrder();
  ASSERT_EQ(tree.Delete(5), false);

  tree.Insert(5);
  tree.Insert(3);
  tree.Insert(4);

  tree.Delete(4);
  Node* return_node = tree.Search(3);
  ASSERT_EQ(return_node->left, nullptr);
  ASSERT_EQ(return_node->right, nullptr);
}

TEST(BinarySearchTreeTest, DeleteNodeWithOneChild){
  BinarySearchTree tree;

  tree.Insert(8);
  tree.Insert(5);
  tree.Insert(7);
  tree.Insert(6);

  // Testing the removal of a single child node on the left side of the root node
  ASSERT_EQ(tree.Delete(5), true);
  Node* return_node = tree.Search(8);
  ASSERT_EQ(return_node->left->data, 7);
  ASSERT_EQ(return_node->right, nullptr);
  ASSERT_EQ(tree.Delete(5), false);
  tree.Delete(7);
  return_node = tree.Search(8);
  ASSERT_EQ(return_node->left->data, 6);
  ASSERT_EQ(return_node->right, nullptr);
  tree.Delete(8);
  return_node = tree.Search(8);
  ASSERT_EQ(return_node, nullptr);
  tree.PrintLevelOrder();

  BinarySearchTree tree2;
  tree2.Insert(5);
  tree2.Insert(8);
  tree2.Insert(10);
  tree2.Insert(9);

  // Testing the removal of a single child node on the right side of the root node
  ASSERT_EQ(tree2.Delete(1), false);
  tree2.Delete(8);
  return_node = tree2.Search(5);
  ASSERT_EQ(return_node->right->data, 10);
  ASSERT_EQ(return_node->right->left->data, 9);
  tree2.Delete(10);
  return_node = tree2.Search(5);
  ASSERT_EQ(return_node->right->data,9);
  tree2.Delete(5);
  return_node = tree2.Search(5);
  ASSERT_EQ(return_node, nullptr);
  tree2.PrintLevelOrder();
}

TEST(BinarySearchTreeTest, DeleteNodeWithTwoChildren){
  BinarySearchTree tree;
  tree.Insert(5);
  tree.Insert(3);
  tree.Insert(7);
  tree.Insert(4);
  tree.Insert(6);
  tree.Insert(8);

  // Deleting root node
  /*************************************************
  *       5                6
  *     /   \            /   \
  *    3     7    ==>   3     7
  *     \   / \          \     \
  *      4 6   8          4     8
  *************************************************/
  ASSERT_EQ(tree.Delete(5), true);
  Node* return_node = tree.Search(6);
  ASSERT_EQ(return_node->left->data, 3);
  ASSERT_EQ(return_node->right->data, 7);
  ASSERT_EQ(return_node->right->left, nullptr); // Test that node deleted properly

  // Delete node from right side of the tree
  BinarySearchTree tree2;
  tree2.Insert(10);
  tree2.Insert(3);
  tree2.Insert(15);
  tree2.Insert(1);
  tree2.Insert(4);
  tree2.Insert(2);
  tree2.Insert(5);
  tree2.Insert(11);
  tree2.Insert(20);
  tree2.Insert(16);
  tree2.Insert(18);
  tree2.Insert(21);
  tree2.Insert(17);
  tree2.Insert(19);

  ASSERT_EQ(tree2.Delete(15),true);
  return_node = tree2.Search(16);
  ASSERT_EQ(return_node->left->data, 11);
  ASSERT_EQ(return_node->right->data, 20);
  ASSERT_EQ(return_node->right->left->data, 18);
  ASSERT_EQ(return_node->right->left->left->data, 17);
  ASSERT_EQ(return_node->right->left->right->data, 19);

  // Delete node from left side of the tree
  ASSERT_EQ(tree2.Delete(3), true);
  ASSERT_EQ(tree2.Search(3), nullptr);
  return_node = tree2.Search(4);
  ASSERT_EQ(return_node->left->data, 1);
  ASSERT_EQ(return_node->right->data, 5);
  ASSERT_EQ(return_node->left->right->data, 2);

  // Delete root with only two childre
  BinarySearchTree tree3;
  tree3.Insert(5);
  tree3.Insert(4);
  tree3.Insert(3);
  ASSERT_EQ(tree3.Delete(5), true);
  return_node = tree3.Search(4);
  ASSERT_EQ(return_node->left->data, 3);
  ASSERT_EQ(return_node->right, nullptr);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
