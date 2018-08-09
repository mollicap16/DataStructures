#include <BinarySearchTree.h>
#include <iostream>
#include <queue>

BinarySearchTree::BinarySearchTree() : root_(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
  delete root_;
}

void BinarySearchTree::Insert(int32_t value){
  Node* new_node = new Node();
  Node* current_node = root_;
  Node* parent_node = new Node();

  new_node->data = value;
  new_node->left = nullptr;
  new_node->right = nullptr;

  if (root_ == nullptr)
    root_ = new_node;
  else{
    while (true){
      parent_node = current_node;

      // Go down the left side of the tree
      if (value <= parent_node->data){
        current_node = current_node->left;

        if(current_node == nullptr){
          parent_node->left = new_node;
          return;
        }
      }
      // Go down the right side of the tree
      else{
        current_node = current_node->right;

        if (current_node == nullptr){
          parent_node->right = new_node;
          return;
        }
      }
    }
  }
}

void BinarySearchTree::InsertRecursively(int32_t value){
  InsertRecursively(&root_, value);
}

void BinarySearchTree::InsertRecursively(Node **node, int32_t value){
  // Base case: If the node is nullptr insert a new node.
  if (*node == nullptr){
    Node* new_node = new Node();
    new_node->data = value;
    *node = new_node;
    return;
  }

  // Go down the left side of the tree
  if (value <= (*node)->data){
    InsertRecursively(&(*node)->left, value);
    return;
  }

  // Go down the right side of the tree
  if (value > (*node)->data){
    InsertRecursively(&(*node)->right, value);
    return;
  }
}

// Search for a value in the tree without using recursion
Node* BinarySearchTree::Search(int32_t value){
  Node* current_node = root_;

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

Node* BinarySearchTree::SearchRecursively(int32_t value){
  return SearchRecursively(root_, value);
}

Node* BinarySearchTree::SearchRecursively(Node *root, int32_t value){
  // Base Cases: Node is either null or value is equal to node value
  if(root == nullptr || root->data == value)
    return root;

  // Value is greater than root's key
  if (root->data < value)
    return SearchRecursively(root->right, value);

  // Value is less than root's key
  return SearchRecursively(root->left, value);
}

void BinarySearchTree::PrintLevelOrder(){
  Node* current_node = new Node();
  current_node = root_;
  std::queue<Node*> queue;

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

// Initiate the recursive function to print in preorder
void BinarySearchTree::PrintPreorder(){
  std::cout << "Print Pre Order Tree: \n";
  PreorderTraversal(root_);
  std::cout << std::endl;
}

// Pre order traversal goes Root Left Right
void BinarySearchTree::PreorderTraversal(Node *node){
  // Base Case
  if (node == nullptr)
    return;

  // Print root data
  std::cout << node->data << " ";

  // Traverse left node
  PreorderTraversal(node->left);

  // Traverse right node
  PreorderTraversal(node->right);
}

void BinarySearchTree::PrintInOrder(){
  std::cout << "Print In Order Tree: \n";
  InorderTraversal(root_);
  std::cout << std::endl;
}

void BinarySearchTree::InorderTraversal(Node *node){
  // Base case
  if (node == nullptr)
    return;

  // Traverse left node
  InorderTraversal(node->left);

  // Print root data
  std::cout << node->data << " ";

  // Traverse right node
  InorderTraversal(node->right);
}

void BinarySearchTree::PrintPostorder(){
  std::cout << "Print Post Order Tree: \n";
  PostorderTraversal(root_);
  std::cout << std::endl;
}

void BinarySearchTree::PostorderTraversal(Node *node){
  // Base case
  if (node == nullptr)
    return;

  // Traverse left node
  PostorderTraversal(node->left);

  // Traverse right node
  PostorderTraversal(node->right);

  std::cout << node->data << " ";
}

// TODO: Clean up function
bool BinarySearchTree::Delete(int32_t value){
  Node* current_node = root_;
  Node* parent_node = root_;

  // Search for value
  while(current_node != nullptr){
    if (current_node->data == value)
      break;
    else if (value < current_node->data){
      parent_node = current_node;
      current_node = current_node->left;
    }
    else if (value > current_node->data){
      parent_node = current_node;
      current_node = current_node->right;
    }
  }

  if (current_node == nullptr)
    return false;

  // Case: No children
  if (current_node->left == nullptr && current_node->right == nullptr){
    // Only One element in the tree
    if (parent_node == current_node){
      root_ = nullptr;
      delete parent_node;
      delete current_node;
      return true;
    }
    if(parent_node->left == current_node){
      std::cout << "Left Node" << std::endl;
      parent_node->left = nullptr;
      delete current_node;
      return true;
    }
    if (parent_node->right == current_node){
      parent_node->right = nullptr;
      delete current_node;
      return true;
    }
  }
  // Case Two Children: Implemented by replacing the node with the min value
  // of the right sub tree.
  else if (current_node->left != nullptr && current_node->right != nullptr){
    Node* inorder_parent_node_ = current_node;
    Node* inorder_node_ =  current_node;
    inorder_node_ = inorder_node_->right;

    // Find inorder succesor which is the minimum value of the right subtree
    while(inorder_node_->left != nullptr){
      inorder_parent_node_ = inorder_node_;
      inorder_node_ = inorder_node_->left;
    }

    // move data from the inorder successor to the node we want to delete
    current_node->data = inorder_node_->data;

    // if the inorder successor has a right child we mush attach it
    // back to the parent before we delete the inorder successor node.
    if(inorder_parent_node_->left->data == inorder_node_->data){
      inorder_parent_node_->left = inorder_node_->right;
    }
    else if (inorder_parent_node_->right->data == inorder_node_->data){
      inorder_parent_node_->right = inorder_node_->right;
    }
    else {
      inorder_parent_node_->left = nullptr;
    }

    // delete inorder node
    delete inorder_node_;
    return true;
  }
  // Case: One Child
  else{
    // Left child is not null
    if (current_node->left != nullptr){
      // Checking if we are deleting the root node
      if (root_ == current_node){
        root_ =  current_node->left;
        delete current_node;
        return true;
      }
      // Checking to see if the current node came from the parent's
      // left or right child.
      if (parent_node->left == current_node){
        parent_node->left = current_node->left;
        delete current_node;
        return true;
      }
      if (parent_node->right == current_node){
        parent_node->right = current_node->left;
        delete current_node;
        return true;
      }
    }
    // Right child is not null
    else if (current_node->right != nullptr){
      // Checking if we are deleting the root node
      if (root_ == current_node){
        root_ =  current_node->right;
        delete current_node;
        return true;
      }
      // Checking to see if the current node came from the parent's
      // left or right child.
      if (parent_node->left == current_node){
        parent_node->left = current_node->right;
        delete current_node;
        return true;
      }
      if (parent_node->right == current_node){
        parent_node->right = current_node->right;
        delete current_node;
        return true;
      }
    }
  }

  return false;
}
