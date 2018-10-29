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
  new_node->null_flag = false;
  new_node->left = nullptr;
  new_node->right = nullptr;
  new_node->parent = nullptr;

  // Insert node into tree
  BstInsert(root_, new_node);

  // Check for Violation
  FixInsertViolations(new_node);
}

void RedBlackTree::BstInsert(RedBlackNode* &root, RedBlackNode* &node){
  // If the tree is empty insert the node as root
  if (root == nullptr){
    node->color = NodeColor::kBlack;
    root = node;
    node->parent = nullptr;
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
    node->parent = nullptr;
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
      RotateLeftLeft(parent_node, grandparent_node);

    else if(grandparent_node->left == parent_node && parent_node->right == child_node)
      RotateLeftRight(child_node, parent_node, grandparent_node);

    else if(grandparent_node->right == parent_node && parent_node->left == child_node)
      RotateRightLeft(child_node, parent_node, grandparent_node);

    else if (grandparent_node->right == parent_node && parent_node->right == child_node)
      RotateRightRight(parent_node, grandparent_node);
  }
  root_->parent = nullptr;
}

void RedBlackTree::PrintLevelOrder(){
  RedBlackNode* current_node = new RedBlackNode();
  current_node = root_;
  std::queue<RedBlackNode*> queue;

  std::cout << "Print Level Order Tree: \n";
  while (current_node != nullptr){
    std::cout << current_node->data;
    if (current_node->color == NodeColor::kRed)
      std::cout << "(R) ";
    if (current_node->color == NodeColor::kBlack)
      std::cout << "(B) ";
    if (current_node->color == NodeColor::kDoubleBlack)
      std::cout << "(BB) ";

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

// Initiate the recursive function to print in preorder
void RedBlackTree::PrintPreorder(){
  std::cout << "Print Pre Order Tree: \n";
  PreorderTraversal(root_);
  std::cout << std::endl;
}

// Pre order traversal goes Root Left Right
void RedBlackTree::PreorderTraversal(RedBlackNode* node){
  // Base Case
  if (node == nullptr)
    return;

  // Print root data
  std::cout << node->data;
  if (node->color == NodeColor::kRed)
    std::cout << "(R) ";
  if (node->color == NodeColor::kBlack)
    std::cout << "(B) ";
  if (node->color == NodeColor::kDoubleBlack)
    std::cout << "(BB) ";

  // Traverse left node
  PreorderTraversal(node->left);

  // Traverse right node
  PreorderTraversal(node->right);
}

void RedBlackTree::PrintInorder(){
  std::cout << "Print In Order Tree: \n";
  InorderTraversal(root_);
  std::cout << std::endl;
}

void RedBlackTree::InorderTraversal(RedBlackNode* node){
  // Base case
  if (node == nullptr)
    return;

  // Traverse left node
  InorderTraversal(node->left);

  // Print root data
  std::cout << node->data;
  if (node->color == NodeColor::kRed)
    std::cout << "(R) ";
  if (node->color == NodeColor::kBlack)
    std::cout << "(B) ";
  if (node->color == NodeColor::kDoubleBlack)
    std::cout << "(BB) ";

  // Traverse right node
  InorderTraversal(node->right);
}

void RedBlackTree::PrintPostorder(){
  std::cout << "Print Post Order Tree: \n";
  PostorderTraversal(root_);
  std::cout << std::endl;
}

void RedBlackTree::PostorderTraversal(RedBlackNode *node){
  // Base case
  if (node == nullptr)
    return;

  // Traverse left node
  PostorderTraversal(node->left);

  // Traverse right node
  PostorderTraversal(node->right);

  std::cout << node->data;
  if (node->color == NodeColor::kRed)
    std::cout << "(R) ";
  if (node->color == NodeColor::kBlack)
    std::cout << "(B) ";
  if (node->color == NodeColor::kDoubleBlack)
    std::cout << "(BB) ";
}

void RedBlackTree::RotateLeftLeft(RedBlackNode *&parent, RedBlackNode *&grandparent){
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

void RedBlackTree::RotateRightRight(RedBlackNode *&parent, RedBlackNode *&grandparent){
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

bool RedBlackTree::Remove(int32_t value){
  RedBlackNode* delete_node = Search(value);

  if (delete_node == nullptr)
    return false;

  RedBlackNode* inorder_predecessor = nullptr;
  if (delete_node->left)
    inorder_predecessor = FindMax(delete_node->left);
  else if (delete_node->right)
    inorder_predecessor = FindMin(delete_node->right);

  if (inorder_predecessor == nullptr){
    inorder_predecessor = delete_node;
  }

  // Case 0: Deleting root node without any children
  if (delete_node == root_ && delete_node->left == nullptr && delete_node->right == nullptr){
    root_ = nullptr;
    delete delete_node;
    return true;
  }
  // Case 1: In Order Predecessor is a red node.
  else if (inorder_predecessor->color == NodeColor::kRed){
    RemoveCase1(inorder_predecessor, delete_node);
    return true;
  }
  // Case 2: If the child of the in order predecessor is red
  else if (inorder_predecessor->left && inorder_predecessor->left->color == NodeColor::kRed){
    RemoveCase2(inorder_predecessor, delete_node);
    return true;
  }
  // Case 3: If the in order predecessor is black
  else if (inorder_predecessor->color == NodeColor::kBlack){
    delete_node->data = inorder_predecessor->data;
    RedBlackNode* double_black_null_node = new RedBlackNode();
    RedBlackNode* double_black_node = inorder_predecessor->left;
    RedBlackNode* double_black_parent = inorder_predecessor->parent;
    RedBlackNode* double_black_sibling = FindSibling(inorder_predecessor);

    if (inorder_predecessor->left != nullptr && inorder_predecessor->left->color == NodeColor::kBlack){
      double_black_node->color = NodeColor::kDoubleBlack;
    }

    if (inorder_predecessor->parent->left == inorder_predecessor){
      inorder_predecessor->parent->left = inorder_predecessor->left;
      if (inorder_predecessor->left){
        inorder_predecessor->left->parent = inorder_predecessor->parent;
      }
      double_black_parent->left = double_black_null_node;
    }
    else if (inorder_predecessor->parent->right == inorder_predecessor){
      inorder_predecessor->parent->right = inorder_predecessor->left;
      if (inorder_predecessor->left){
        inorder_predecessor->left->parent = inorder_predecessor->parent;
      }
      double_black_parent->right = double_black_null_node;
    }

    delete inorder_predecessor;

    if (double_black_node == nullptr){
      double_black_node = double_black_null_node;
      double_black_node->null_flag = true;
      double_black_node->parent = double_black_parent;
      double_black_node->color = NodeColor::kDoubleBlack;
    }

    while (double_black_node->color == NodeColor::kDoubleBlack){
      // Remove Case 3-1 (Terminal)
      if (double_black_node == root_){
        RemoveCase3_1(double_black_node);
        if (double_black_node->null_flag){
          delete double_black_node;
        }
        return true;
      }
      // Remove Case 3-2
      else if (double_black_parent->color == NodeColor::kBlack && double_black_sibling->color == NodeColor::kRed){
        RemoveCase3_2(double_black_node, double_black_parent, double_black_sibling);
      }
      // Remove Case 3-3
      else if(double_black_parent->color == NodeColor::kBlack && double_black_sibling->color == NodeColor::kBlack &&
              InnerChildColor(double_black_parent, double_black_sibling) == NodeColor::kBlack &&
              OuterChildColor(double_black_parent, double_black_sibling) == NodeColor::kBlack){
        RemoveCase3_3(double_black_node, double_black_parent, double_black_sibling);
      }
      // Remove Case 3-4 (Terminal)
      else if (double_black_parent->color == NodeColor::kRed && OuterChildColor(double_black_parent, double_black_sibling) != NodeColor::kRed
               && InnerChildColor(double_black_parent, double_black_sibling) != NodeColor::kRed){

        RemoveCase3_4(double_black_node, double_black_parent, double_black_sibling);

        // Delete double black node if it
        if (double_black_node->null_flag){
          if (double_black_parent->left == double_black_node)
            double_black_parent->left = nullptr;
          else if (double_black_parent->right == double_black_node)
            double_black_parent->right = nullptr;
          delete double_black_node;
        }

        return true;
      }
      // Remove Case 3-5
      else if (double_black_sibling->color == NodeColor::kBlack &&
               OuterChildColor(double_black_parent, double_black_sibling) == NodeColor::kBlack &&
               InnerChildColor(double_black_parent, double_black_sibling) == NodeColor::kRed){

        RemoveCase3_5(double_black_node, double_black_parent, double_black_sibling);
      }
      // Remove Case 3-6 (Terminal)
      else if (double_black_sibling->color == NodeColor::kBlack  && OuterChildColor(double_black_parent, double_black_sibling) == NodeColor::kRed){
        RemoveCase3_6(double_black_node, double_black_parent, double_black_sibling);

        if (double_black_node->null_flag){
          if (double_black_parent->left == double_black_node)
            double_black_parent->left = nullptr;
          else if (double_black_parent->right == double_black_node)
            double_black_parent->right = nullptr;

          delete double_black_node;
        }

        return true;
      }
      // ERROR
      else{
        std::cout << "Error in remove case 3" << std::endl;
        return false;
      }
    }
  }

  return false;
}

void RedBlackTree::RemoveCase1(RedBlackNode* &inorder_predecessor, RedBlackNode* &delete_node){
  delete_node->data = inorder_predecessor->data;

  if (inorder_predecessor->parent->left == inorder_predecessor)
    inorder_predecessor->parent->left = nullptr;
  else if (inorder_predecessor->parent->right == inorder_predecessor)
    inorder_predecessor->parent->right = nullptr;

  delete inorder_predecessor;
}

void RedBlackTree::RemoveCase2(RedBlackNode* &inorder_predecessor, RedBlackNode* &delete_node){
  delete_node->data = inorder_predecessor->data;
  // Replace red child node with in order predecessor.
  if (inorder_predecessor == inorder_predecessor->parent->left){
    inorder_predecessor->parent->left = inorder_predecessor->left;
    inorder_predecessor->left->parent = inorder_predecessor->parent;
  }
  if (inorder_predecessor == inorder_predecessor->parent->right){
    inorder_predecessor->parent->right = inorder_predecessor->left;
    inorder_predecessor->left->parent = inorder_predecessor->parent;
  }
  inorder_predecessor->left->color = NodeColor::kBlack;
  inorder_predecessor->parent = nullptr;
  delete inorder_predecessor;
}

// Terminal Remove Case
void RedBlackTree::RemoveCase3_1(RedBlackNode *&double_black_node){
  root_->color = NodeColor::kBlack;
  double_black_node->color = NodeColor::kBlack;
}

void RedBlackTree::RemoveCase3_2(RedBlackNode* &double_black_node, RedBlackNode* &double_black_parent, RedBlackNode* &double_black_sibling){
  // Sibling Node is right child of parent (left rotation)
  if (double_black_parent->left == double_black_node){
    RotateLeft(double_black_parent);
  }
  // Sibling Node is left child of parent node (right rotation)
  else if (double_black_parent->right == double_black_node){
    RotateRight(double_black_parent);
  }

  // Perform color change
  double_black_sibling->color = NodeColor::kBlack;
  double_black_parent->color = NodeColor::kRed;
  double_black_sibling = FindSibling(double_black_node);
  double_black_parent = double_black_node->parent;
}

void RedBlackTree::RemoveCase3_3(RedBlackNode* &double_black_node, RedBlackNode* &double_black_parent, RedBlackNode* &double_black_sibling){
  RedBlackNode* double_black_delete_node = nullptr;

  double_black_sibling->color = NodeColor::kRed;
  double_black_node->color = NodeColor::kBlack;
  double_black_parent->color = NodeColor::kDoubleBlack;

  if (double_black_node->null_flag){
    double_black_delete_node = double_black_node;

    if (double_black_parent->left == double_black_node)
      double_black_parent->left = nullptr;
    else if (double_black_parent->right == double_black_node)
      double_black_parent->right = nullptr;

    delete double_black_delete_node;
  }

  double_black_node = double_black_parent;
  double_black_parent = double_black_parent->parent;
  double_black_sibling = FindSibling(double_black_node);
}

// Terminal Remove Case
void RedBlackTree::RemoveCase3_4(RedBlackNode *&double_black_node, RedBlackNode *&double_black_parent, RedBlackNode *&double_black_sibling){
  double_black_sibling->color = NodeColor::kRed;
  double_black_parent->color = NodeColor::kBlack;
  double_black_node->color = NodeColor::kBlack;
}

void RedBlackTree::RemoveCase3_5(RedBlackNode* &double_black_node, RedBlackNode* &double_black_parent, RedBlackNode* &double_black_sibling){
  // Sibling Node is right child of parent (right rotation);
  if (double_black_parent->left == double_black_node){
    RotateRight(double_black_sibling);
  }
  // Sibling Node is the left child of parent (left rotation);
  else if (double_black_parent->right == double_black_node){
    RotateLeft(double_black_sibling);
  }

  // Recolor
  double_black_sibling->color = NodeColor::kRed;
  double_black_sibling->parent->color = NodeColor::kBlack;
  double_black_sibling = FindSibling(double_black_node);
}

// Terminal Remove Case
void RedBlackTree::RemoveCase3_6(RedBlackNode* &double_black_node, RedBlackNode* &double_black_parent, RedBlackNode* &double_black_sibling){
  // Sibling Node is right child of parent (left rotation)
  if (double_black_sibling == double_black_parent->right){
    RotateLeft(double_black_parent);
    double_black_sibling->right->color = NodeColor::kBlack;
  }
  // Sibling Node is left child of parent (right rotation)
  else if (double_black_sibling == double_black_parent->left){
    RotateRight(double_black_parent);
    double_black_sibling->left->color = NodeColor::kBlack;
  }

  double_black_sibling->color = double_black_parent->color;
  double_black_node->color = NodeColor::kBlack;
  double_black_parent->color = NodeColor::kBlack;
}

void RedBlackTree::RotateLeft(RedBlackNode* &parent_node){
  RedBlackNode* right_node = parent_node->right;

  parent_node->right = right_node->left;
  if (right_node->left)
    right_node->left->parent = parent_node;
  right_node->parent = parent_node->parent;
  if (parent_node->parent == nullptr){
    root_ = right_node;
  }
  else if(parent_node == parent_node->parent->left){
    parent_node->parent->left = right_node;
  }
  else if(parent_node == parent_node->parent->right){
    parent_node->parent->right = right_node;
  }

  right_node->left = parent_node;
  parent_node->parent = right_node;
}

void RedBlackTree::RotateRight(RedBlackNode* &parent_node){
  RedBlackNode* left_node = parent_node->left;

  parent_node->left = left_node->right;
  if (left_node->right)
    left_node->right->parent = parent_node;
  left_node->parent = parent_node->parent;
  if (parent_node->parent == nullptr){
    root_ = left_node;
  }
  else if(parent_node == parent_node->parent->right){
    parent_node->parent->right = left_node;
  }
  else if(parent_node == parent_node->parent->left){
    parent_node->parent->left = left_node;
  }

  left_node->right = parent_node;
  parent_node->parent = left_node;
}

RedBlackNode* RedBlackTree::FindMin(RedBlackNode *&node){
  if (node == nullptr)
    return nullptr;

  RedBlackNode* current_node = node;
  while(current_node->left != nullptr){
    current_node = current_node->left;
  }

  return current_node;
}

RedBlackNode* RedBlackTree::FindMax(RedBlackNode *&node){
  if (node == nullptr)
    return nullptr;

  RedBlackNode* current_node = node;
  while (current_node->right != nullptr){
    current_node = current_node->right;
  }

  return current_node;
}

RedBlackNode* RedBlackTree::FindSibling(RedBlackNode *&node){
  if (node == nullptr || node->parent == nullptr)
    return nullptr;

  if (node->parent->left == node)
    return node->parent->right;
  else if (node->parent->right == node)
    return node->parent->left;

  return nullptr;
}

NodeColor RedBlackTree::OuterChildColor(RedBlackNode *&parent, RedBlackNode *&child_node){
  if (parent == nullptr || child_node == nullptr)
    return NodeColor::kNull;

  if (parent->left == child_node){
    if (child_node->left)
      return child_node->left->color;
    else
      return NodeColor::kBlack;
  }
  else if (parent->right == child_node){
    if (child_node->right)
      return child_node->right->color;
    else
      return NodeColor::kBlack;
  }

  return NodeColor::kNull;
}

NodeColor RedBlackTree::InnerChildColor(RedBlackNode *&parent, RedBlackNode *&child_node){
  if (parent == nullptr || child_node == nullptr)
    return NodeColor::kNull;

  if (parent->left == child_node){
    if (child_node->right)
      return child_node->right->color;
    else
      return NodeColor::kBlack;
  }
  else if (parent->right == child_node){
    if (child_node->left)
      return child_node->left->color;
    else
      return NodeColor::kBlack;
  }

  return NodeColor::kNull;
}

bool RedBlackTree::IsEmpty(){
  if (root_ == nullptr)
    return true;
  else
    return false;
}
