#include <red_black_tree.h>
#include <iostream>
#include <limits>
#include <queue>

RedBlackTree::RedBlackTree() : root_(nullptr)
{}

RedBlackTree::~RedBlackTree(){
  delete root_;
}

RedBlackNode* RedBlackTree::Search(int32_t value){
  RedBlackNode* current_node = root_;

  if (current_node == nullptr)
    return current_node;
  else {
    while(current_node != nullptr){
      if (current_node->data == value){
        return current_node;
      }
      else{
        if (value < current_node->data){
          current_node = current_node->left;
        }
        else{
          current_node = current_node->right;
        }
      }
    }
  }

  return current_node;
}

void RedBlackTree::Insert(int32_t value){
  RedBlackNode* new_node = new RedBlackNode();
  new_node->data = value;
  new_node->color = NodeColor::kRed;
  new_node->left = nullptr;
  new_node->right = nullptr;
  new_node->parent = nullptr;

  // Insert node into tree
  InsertBst(root_, new_node);

  // Check for Violation
  FixInsertViolations(new_node);

}

void RedBlackTree::InsertBst(RedBlackNode* &root, RedBlackNode* &node){
  // If the tree is empty insert the node as root
  if (root == nullptr){
    node->color = NodeColor::kBlack;
    root = node;
    return;
  }
  else{
    RedBlackNode* current_node = root;
    RedBlackNode* parent_node = new RedBlackNode();
    while(true){
      parent_node = current_node;

      // Iterate down left node
      if (node->data <= parent_node->data){
        current_node = current_node->left;

        if(current_node == nullptr){
          node->parent = parent_node;
          parent_node->left = node;
          return;
        }
      }
      // Iterate down right node
      else{
        current_node = current_node->right;

        if(current_node == nullptr){
          node->parent = parent_node;
          parent_node->right = node;
          return;
        }
      }
    }
  }
}

void RedBlackTree::FixInsertViolations(RedBlackNode *&node){
  if (node == root_){
    if (node->color != NodeColor::kBlack){
      node->color = NodeColor::kBlack;
    }
    return;
  }

  RedBlackNode* grandparent_node = nullptr;
  RedBlackNode* parent_node = nullptr;
  RedBlackNode* uncle_node = nullptr;
  RedBlackNode* child_node = node;

  parent_node = node->parent;
  grandparent_node = parent_node->parent;
  if (grandparent_node != nullptr){
    if (grandparent_node->left == parent_node)
      uncle_node = grandparent_node->right;
    else
      uncle_node = grandparent_node->left;
  }

  if (parent_node == root_)
    return;

  // Recolor
  while(uncle_node != nullptr && uncle_node->color == NodeColor::kRed && parent_node->color == NodeColor::kRed){
    uncle_node->color = NodeColor::kBlack;
    parent_node->color = NodeColor::kBlack;
    if (grandparent_node != root_){
      grandparent_node->color = NodeColor::kRed;
      child_node = grandparent_node;
      parent_node = child_node->parent;
      grandparent_node = parent_node->parent;
      // TODO: Create a function to find the uncle node
      if (grandparent_node != nullptr){
        if (grandparent_node->left == parent_node)
          uncle_node = grandparent_node->right;
        else if (grandparent_node->right == parent_node)
          uncle_node = grandparent_node->left;
      }
      else{
        uncle_node = nullptr;
      }
    }
  }
  // Rotations
  if(grandparent_node && parent_node->color == NodeColor::kRed && (!uncle_node || uncle_node->color == NodeColor::kBlack)){
    if(grandparent_node->left == parent_node && parent_node->left == child_node)
      RotateLeftLeft(child_node, parent_node, grandparent_node);
    else if(grandparent_node->left == parent_node && parent_node->right == child_node)
      RotateLeftRight(child_node, parent_node, grandparent_node);
    else if(grandparent_node->right == parent_node && parent_node->left == child_node)
      RotateRightLeft(child_node, parent_node, grandparent_node);
    else if (grandparent_node->right == parent_node && parent_node->right == child_node)
      RotateRightRight(child_node, parent_node, grandparent_node);
  }
}

void RedBlackTree::PrintLevelOrder(){
  RedBlackNode* current_node = new RedBlackNode();
  current_node = root_;
  std::queue<RedBlackNode*> queue;

  std::cout << "Print Level Order Tree: \n";
  while (current_node != nullptr){
    std::cout << current_node->data << " ";

    // First push the left child node onto the queue, if there is one. Then push the right
    // child node onto the queue, if there is one.
    if(current_node->left != nullptr)
      queue.push(current_node->left);
    if(current_node->right != nullptr)
      queue.push(current_node->right);

    if (queue.size() > 0){
      current_node = queue.front();
      queue.pop();
    } else{
      current_node = nullptr;
    }
  }

  std::cout << std::endl;
}


void RedBlackTree::RotateLeftLeft(RedBlackNode *&/*child*/, RedBlackNode *&parent, RedBlackNode *&grandparent){
  RedBlackNode* parent_right_node = parent->right;
  // Recolor
  parent->color = NodeColor::kBlack;
  grandparent->color = NodeColor::kRed;

  // Restructure
  if (grandparent->parent != nullptr){
    if (grandparent->parent->left == grandparent)
      grandparent->parent->left = parent;
    else if (grandparent->parent->right == grandparent)
      grandparent->parent->right = parent;
    parent->parent = grandparent->parent;
  }
  else
    root_ = parent;

  parent->right = grandparent;
  grandparent->parent = parent;
  grandparent->left = parent_right_node;

  if (parent_right_node != nullptr)
    parent_right_node->parent = grandparent;
}

void RedBlackTree::RotateLeftRight(RedBlackNode *&child, RedBlackNode *&parent, RedBlackNode *&grandparent){
  RedBlackNode* child_left_node = child->left;
  RedBlackNode* child_right_node = child->right;

  // Recolor
  child->color = NodeColor::kBlack;
  grandparent->color = NodeColor::kRed;

  // Restructure
  if (grandparent->parent != nullptr){
    if (grandparent->parent->left == grandparent)
      grandparent->parent->left = child;
    else if (grandparent->parent->right == grandparent)
      grandparent->parent->right = child;

    child->parent = grandparent->parent;
  }
  else{
    root_ = child;
    child->parent = root_;
  }

  child->left = parent;
  parent->parent = child;
  child->right = grandparent;
  grandparent->parent = child;
  parent->right = child_left_node;
  grandparent->left = child_right_node;

  if (child_left_node != nullptr)
    child_left_node->parent = parent;
  if (child_right_node != nullptr)
    child_right_node->parent = grandparent;

}

void RedBlackTree::RotateRightLeft(RedBlackNode *&child, RedBlackNode *&parent, RedBlackNode *&grandparent){
  RedBlackNode* child_left_node = child->left;
  RedBlackNode* child_right_node = child->right;

  // Recolor
  child->color = NodeColor::kBlack;
  grandparent->color = NodeColor::kRed;

  // Restructure
  if (grandparent->parent != nullptr){
    if (grandparent->parent->left == grandparent)
      grandparent->parent->left = child;
    else if (grandparent->parent->right == grandparent)
      grandparent->parent->right = child;
    child->parent = grandparent->parent;
  }
  else{
    root_ = child;
    child->parent = root_;
  }

  child->right = parent;
  parent->parent = child;
  child->left = grandparent;
  grandparent->parent = child;
  parent->left = child_right_node;
  grandparent->right = child_left_node;

  if (child_left_node != nullptr)
    child_left_node->parent = grandparent;
  if (child_right_node != nullptr)
    child_right_node->parent = parent;

}

void RedBlackTree::RotateRightRight(RedBlackNode *&/*child*/, RedBlackNode *&parent, RedBlackNode *&grandparent){
  RedBlackNode* parent_left_node = parent->left;
  // Recolor
  parent->color = NodeColor::kBlack;
  grandparent->color = NodeColor::kRed;

  // Restructure
  if (grandparent->parent != nullptr){
    if (grandparent->parent->left == grandparent)
      grandparent->parent->left = parent;
    else if (grandparent->parent->right == grandparent)
      grandparent->parent->right = parent;
    parent->parent = grandparent->parent;
  }
  else
    root_ = parent;

  parent->left = grandparent;
  grandparent->parent = parent;
  grandparent->right = parent_left_node;

  if (parent_left_node != nullptr)
    parent_left_node->parent = grandparent;
}
