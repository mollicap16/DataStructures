#include <iostream>
#include <gtest/gtest.h>
#include <red_black_tree.h>

TEST(RedBlackTreeTest, SearchTestNull){
  RedBlackTree rb_tree;
  RedBlackNode* search_node = rb_tree.Search(0);

  ASSERT_EQ(search_node, nullptr);
}

TEST(RedBlackTreeTest, SearchTestWithDataReturnNull){
  RedBlackTree rb_tree;
  RedBlackNode* search_node;
  rb_tree.Insert(10);
  rb_tree.Insert(20);

  search_node = rb_tree.Search(90);
  ASSERT_EQ(search_node, nullptr);
}

TEST(RedBlackTreeTest, InsertTest){
  RedBlackTree rb_tree;
  RedBlackNode* search_node;

  rb_tree.Insert(10);
  rb_tree.Insert(8);
  rb_tree.Insert(12);
  rb_tree.Insert(7);

  search_node = rb_tree.Search(7);
  ASSERT_EQ(search_node->data, 7);
  ASSERT_EQ(search_node->parent->data, 8);
  ASSERT_EQ(search_node->parent->parent->data, 10);
  ASSERT_EQ(search_node->parent->parent->right->data, 12);
}

TEST(RedBlackTreeTest, RecolorTest){
  RedBlackTree rb_tree;
  RedBlackNode* search_node;

  rb_tree.Insert(10);
  rb_tree.Insert(8);
  rb_tree.Insert(12);

  search_node = rb_tree.Search(12);
  ASSERT_EQ(search_node->color, NodeColor::kRed);
  ASSERT_EQ(search_node->parent->left->color, NodeColor::kRed);

  rb_tree.Insert(7);
  search_node = rb_tree.Search(7);
  ASSERT_EQ(search_node->parent->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->parent->parent->right->color, NodeColor::kBlack);
}

TEST(RedBlackTreeTest, InsertRotateLeftLeftTrivalTest){
  RedBlackTree rb_tree;
  RedBlackNode* search_node;

  rb_tree.Insert(10);
  rb_tree.Insert(8);
  rb_tree.Insert(6);

  search_node = rb_tree.Search(8);
  ASSERT_EQ(search_node->data, 8);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 6);
  ASSERT_EQ(search_node->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->data, 10);
  ASSERT_EQ(search_node->right->color, NodeColor::kRed);

  rb_tree.Insert(4);
  rb_tree.Insert(2);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 4);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->right->data, 6);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->left->data, 2);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kRed);
}

TEST(RedBlackTreeTest, InsertRotateLeftRightTrivalTest){
  RedBlackTree rb_tree;
  RedBlackNode* search_node;

  rb_tree.Insert(10);
  rb_tree.Insert(6);
  rb_tree.Insert(8);
  search_node = rb_tree.Search(8);

  ASSERT_EQ(search_node->data, 8);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 6);
  ASSERT_EQ(search_node->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->data, 10);
  ASSERT_EQ(search_node->right->color, NodeColor::kRed);

  rb_tree.Insert(4);
  rb_tree.Insert(5);

  ASSERT_EQ(search_node->left->data, 5);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->data, 4);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->right->data, 6);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kRed);
}

TEST(RedBlackTreeTest, InsertRotateRightRightTrivalTest){
  RedBlackTree rb_tree;
  RedBlackNode* search_node;

  rb_tree.Insert(10);
  rb_tree.Insert(12);
  rb_tree.Insert(14);
  search_node = rb_tree.Search(12);

  ASSERT_EQ(search_node->data, 12);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 10);
  ASSERT_EQ(search_node->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->data, 14);
  ASSERT_EQ(search_node->right->color, NodeColor::kRed);

  rb_tree.Insert(16);
  rb_tree.Insert(18);
  ASSERT_EQ(search_node->right->data, 16);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 14);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->data, 18);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);
}

TEST(RedBlackTreeTest, InsertRotateRightleftTrivalTest){
  RedBlackTree rb_tree;
  RedBlackNode* search_node;

  rb_tree.Insert(10);
  rb_tree.Insert(20);
  rb_tree.Insert(16);
  search_node = rb_tree.Search(16);

  ASSERT_EQ(search_node->data, 16);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 10);
  ASSERT_EQ(search_node->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->data, 20);
  ASSERT_EQ(search_node->right->color, NodeColor::kRed);

  rb_tree.Insert(25);
  rb_tree.Insert(23);
  ASSERT_EQ(search_node->right->data, 23);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 20);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->data, 25);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);
}

TEST(RedBlackTreeTest, InsertFullTest){
  /*  NOTE: The tool that was used to generate a full test case for
   *        Red Black Trees can be found here:
   *        https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
  */

  RedBlackTree rb_tree;
  RedBlackNode* search_node;

  rb_tree.Insert(30);
  rb_tree.Insert(15);
  rb_tree.Insert(46);
  rb_tree.Insert(20);
  rb_tree.Insert(17);

  search_node = rb_tree.Search(30);
  ASSERT_EQ(search_node->data,30);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 17);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->data, 15);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->right->data, 20);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->data, 46);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);

  // To see a visual reprsentation of the RB Tree enter the values seen below,
  // in order, into the RB Tree tool referenced in the NOTE above.
  rb_tree.Insert(25);
  rb_tree.Insert(50);
  rb_tree.Insert(60);
  rb_tree.Insert(48);
  rb_tree.Insert(49);
  rb_tree.Insert(65);
  rb_tree.Insert(70);
  rb_tree.Insert(80);
  rb_tree.Insert(85);
  rb_tree.Insert(90);
  rb_tree.Insert(95);
  rb_tree.Insert(100);
  rb_tree.Insert(110);
  rb_tree.Insert(68);
  rb_tree.Insert(67);
  rb_tree.Insert(94);
  rb_tree.Insert(98);
  rb_tree.Insert(96);
  rb_tree.Insert(62);
  rb_tree.Insert(63);
  rb_tree.Insert(88);
  rb_tree.Insert(86);

  search_node = rb_tree.Search(65);
  ASSERT_EQ(search_node->data, 65);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 30);
  ASSERT_EQ(search_node->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->data, 90);
  ASSERT_EQ(search_node->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->left->data, 17);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->right->data, 50);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 80);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->data, 100);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kBlack);

  search_node = rb_tree.Search(17);
  ASSERT_EQ(search_node->left->data, 15);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->data, 20);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->data, 25);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);

  search_node = rb_tree.Search(50);
  ASSERT_EQ(search_node->left->data, 48);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->data, 46);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->right->data, 49);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->data, 62);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 60);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->data, 63);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);

  search_node = rb_tree.Search(80);
  ASSERT_EQ(search_node->left->data, 68);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->data, 86);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->data, 67);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->right->data, 70);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->left->data, 85);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->data, 88);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);

  search_node = rb_tree.Search(100);
  ASSERT_EQ(search_node->left->data, 95);
  ASSERT_EQ(search_node->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->data, 110);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->data, 94);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->right->data, 98);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->right->left->data, 96);
  ASSERT_EQ(search_node->left->right->left->color, NodeColor::kRed);


  rb_tree.Insert(27);
  rb_tree.Insert(28);
  rb_tree.Insert(29);
  rb_tree.Insert(22);
  rb_tree.Insert(21);

  search_node = rb_tree.Search(25);
  ASSERT_EQ(search_node->parent->data, 17);
  ASSERT_EQ(search_node->parent->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 21);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->data, 28);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->data, 20);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->right->data, 22);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->left->data, 27);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->data, 29);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);
}

TEST(RedBlackTreeTest, DeleteNonExistingItemTest){
  RedBlackTree rb_tree;
  rb_tree.Insert(10);
  rb_tree.Insert(30);

  ASSERT_EQ(rb_tree.Remove(40), false);
}

TEST(RedBlackTreeTest, DeleteNodeCase1Test){
  RedBlackTree rb_tree;
  RedBlackNode* search_node;
  rb_tree.Insert(50);
  rb_tree.Insert(30);
  rb_tree.Insert(70);

  ASSERT_EQ(rb_tree.Remove(50), true);
  search_node = rb_tree.Search(30);

  ASSERT_EQ(search_node->data, 30);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left, nullptr);
  ASSERT_EQ(search_node->right->data, 70);
  ASSERT_EQ(search_node->right->color, NodeColor::kRed);

  rb_tree.Insert(50);
  rb_tree.Insert(40);
  rb_tree.Insert(90);
  rb_tree.Insert(45);
  rb_tree.Insert(110);
  rb_tree.Insert(48);

  rb_tree.Remove(50);
  search_node = rb_tree.Search(48);
  ASSERT_EQ(search_node->parent, nullptr);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 40);
  ASSERT_EQ(search_node->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->data, 90);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->data, 30);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->right->data, 45);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 70);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->data, 110);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);

  rb_tree.Remove(90);
  ASSERT_EQ(search_node->right->data, 70);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 40);
  ASSERT_EQ(search_node->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->left->data, 30);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->right->data, 45);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left, nullptr);
  ASSERT_EQ(search_node->right->right->data, 110);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);
}

TEST(RedBlackTreeTest, DeleteNodeCase2Test){
  RedBlackTree rb_tree;
  RedBlackNode* search_node;

  rb_tree.Insert(50);
  rb_tree.Insert(90);
  rb_tree.Insert(25);
  rb_tree.Insert(110);
  rb_tree.Insert(95);
  rb_tree.Insert(92);
  rb_tree.Insert(85);
  rb_tree.Insert(80);
  rb_tree.Insert(120);
  rb_tree.Insert(125);
  rb_tree.Insert(130);
  rb_tree.Insert(100);
  rb_tree.Insert(93);

  rb_tree.Remove(95);
  search_node = rb_tree.Search(90);
  ASSERT_EQ(search_node->parent, nullptr);
  ASSERT_EQ(search_node->right->data, 93);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 92);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->data, 120);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->left->data, 110);
  ASSERT_EQ(search_node->right->right->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->right->data, 125);
  ASSERT_EQ(search_node->right->right->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->left->left->data, 100);
  ASSERT_EQ(search_node->right->right->left->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->right->right->data, 130);
  ASSERT_EQ(search_node->right->right->right->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->left->right, nullptr);

  rb_tree.Remove(120);
  ASSERT_EQ(search_node->right->data, 93);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 92);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->data, 110);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->left->data, 100);
  ASSERT_EQ(search_node->right->right->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->right->data, 125);
  ASSERT_EQ(search_node->right->right->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->right->right->data, 130);
  ASSERT_EQ(search_node->right->right->right->right->color, NodeColor::kRed);

  rb_tree.Remove(90);
  search_node = rb_tree.Search(85);
  ASSERT_EQ(search_node->parent, nullptr);
  ASSERT_EQ(search_node->left->data, 50);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->data, 93);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->data, 25);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->right->data, 80);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 92);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->data, 110);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->left->data, 100);
  ASSERT_EQ(search_node->right->right->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->right->data, 125);
  ASSERT_EQ(search_node->right->right->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->right->right->data, 130);
  ASSERT_EQ(search_node->right->right->right->right->color, NodeColor::kRed);

  rb_tree.Remove(125);
  ASSERT_EQ(search_node->parent, nullptr);
  ASSERT_EQ(search_node->left->data, 50);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->data, 93);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 92);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->data, 110);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->left->data, 100);
  ASSERT_EQ(search_node->right->right->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->right->data, 130);
  ASSERT_EQ(search_node->right->right->right->color, NodeColor::kBlack);

}

TEST(RedBlackTreeTest, DeleteNodeCase3Test){
  RedBlackTree rb_tree;
  RedBlackNode* search_node;

  rb_tree.Insert(90);
  rb_tree.Insert(50);
  rb_tree.Insert(95);
  rb_tree.Insert(25);
  rb_tree.Insert(85);
  rb_tree.Insert(80);
  rb_tree.Insert(92);
  rb_tree.Insert(120);
  rb_tree.Insert(110);
  rb_tree.Insert(125);
  rb_tree.Insert(100);
  rb_tree.Insert(93);
  rb_tree.Insert(70);
  rb_tree.Insert(130);
  rb_tree.Insert(123);

  // Delete black leaf node
  rb_tree.Remove(25);
  search_node = rb_tree.Search(90);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 80);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->data, 50);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->right->data, 85);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->right->data, 70);
  ASSERT_EQ(search_node->left->left->right->color, NodeColor::kRed);

  rb_tree.Remove(95);
  rb_tree.Remove(93);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->data, 120);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 100);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->left->left->data, 92);
  ASSERT_EQ(search_node->right->left->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->right->data, 110);
  ASSERT_EQ(search_node->right->left->right->color, NodeColor::kBlack);

  rb_tree.Remove(90);
  search_node = rb_tree.Search(85);
  ASSERT_EQ(search_node->data, 85);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 70);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->data, 120);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->right->data, 80);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->data, 50);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 100);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->data, 125);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->left->data, 92);
  ASSERT_EQ(search_node->right->left->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->right->data, 110);
  ASSERT_EQ(search_node->right->left->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->left->data, 123);
  ASSERT_EQ(search_node->right->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->right->data, 130);
  ASSERT_EQ(search_node->right->right->right->color, NodeColor::kRed);

  rb_tree.Remove(92);
  rb_tree.Remove(70);
  ASSERT_EQ(search_node->data, 85);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 50);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->right->data, 80);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->left, nullptr);
  ASSERT_EQ(search_node->right->data, 120);
  ASSERT_EQ(search_node->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->left->data, 100);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->data, 125);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->right->data, 110);
  ASSERT_EQ(search_node->right->left->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->left->left, nullptr);
  ASSERT_EQ(search_node->right->right->left->data, 123);
  ASSERT_EQ(search_node->right->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->right->data, 130);
  ASSERT_EQ(search_node->right->right->right->color, NodeColor::kRed);

  // Remove a case that isn't there
  ASSERT_EQ(rb_tree.Remove(1), false);

  // Add some more values to test that we can remove and add
  rb_tree.Insert(92);
  rb_tree.Insert(90);
  search_node = rb_tree.Search(100);
  ASSERT_EQ(search_node->data, 100);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 85);
  ASSERT_EQ(search_node->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->data, 120);
  ASSERT_EQ(search_node->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->left->data, 50);
  ASSERT_EQ(search_node->left->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->right->data, 92);
  ASSERT_EQ(search_node->left->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 110);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->right->data, 125);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->left->left, nullptr);
  ASSERT_EQ(search_node->left->left->right->data, 80);
  ASSERT_EQ(search_node->left->left->right->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->right->left->data, 90);
  ASSERT_EQ(search_node->left->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->left->right->right, nullptr);
  ASSERT_EQ(search_node->right->left->left, nullptr);
  ASSERT_EQ(search_node->right->left->right, nullptr);
  ASSERT_EQ(search_node->right->right->left->data, 123);
  ASSERT_EQ(search_node->right->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->right->data, 130);
  ASSERT_EQ(search_node->right->right->right->color, NodeColor::kRed);

  rb_tree.Remove(50);
  rb_tree.Remove(80);
  rb_tree.Remove(85);
  rb_tree.Remove(90);
  rb_tree.Remove(92);
  rb_tree.Remove(120);
  search_node = rb_tree.Search(110);
  ASSERT_EQ(search_node->data, 110);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left->data, 100);
  ASSERT_EQ(search_node->left->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->data, 125);
  ASSERT_EQ(search_node->right->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->right->left->data, 123);
  ASSERT_EQ(search_node->right->left->color, NodeColor::kRed);
  ASSERT_EQ(search_node->right->right->data, 130);
  ASSERT_EQ(search_node->right->right->color, NodeColor::kRed);

  rb_tree.Remove(100);
  rb_tree.Remove(125);
  rb_tree.Remove(123);

  search_node = rb_tree.Search(110);
  ASSERT_EQ(search_node->data, 110);
  ASSERT_EQ(search_node->color, NodeColor::kBlack);
  ASSERT_EQ(search_node->left, nullptr);
  ASSERT_EQ(search_node->right->data, 130);
  ASSERT_EQ(search_node->right->color, NodeColor::kRed);
  ASSERT_EQ(rb_tree.IsEmpty(), false);
  rb_tree.Remove(110);
  rb_tree.Remove(130);
  ASSERT_EQ(rb_tree.IsEmpty(), true);
}

TEST(RedBlackTreeTest, PrintTests){
  RedBlackTree rb_tree;

  rb_tree.Insert(90);
  rb_tree.Insert(50);
  rb_tree.Insert(95);
  rb_tree.Insert(25);
  rb_tree.Insert(85);
  rb_tree.Insert(80);
  rb_tree.Insert(92);
  rb_tree.Insert(120);
  rb_tree.Insert(110);
  rb_tree.Insert(125);
  rb_tree.Insert(100);
  rb_tree.Insert(93);
  rb_tree.Insert(70);
  rb_tree.Insert(130);
  rb_tree.Insert(123);

  rb_tree.PrintLevelOrder();
  rb_tree.PrintPreorder();
  rb_tree.PrintInorder();
  rb_tree.PrintPostorder();
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
