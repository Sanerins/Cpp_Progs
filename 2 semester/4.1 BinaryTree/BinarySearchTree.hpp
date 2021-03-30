#ifndef INC_4_1_BINARYTREE_BINARYSEARCHTREE_HPP
#define INC_4_1_BINARYTREE_BINARYSEARCHTREE_HPP

#include <iostream>
#include <algorithm>
#include "queue.hpp"

template<class T>
class BinarySearchTree
{
public:

  BinarySearchTree();
  BinarySearchTree(const T& root);
  BinarySearchTree(const BinarySearchTree& src) = delete;
  BinarySearchTree(BinarySearchTree&& src) noexcept;

  ~BinarySearchTree();

  BinarySearchTree<T>& operator=(const BinarySearchTree& src) = delete;
  BinarySearchTree<T>& operator=(BinarySearchTree&& src) noexcept;

  bool operator==(const BinarySearchTree& src);

  bool iterativeSearch(const T& key) const;

  bool insert(const T& key);

  bool deleteItem(const T& key);

  void print() const;

  int getCount() const;

  int getHeight() const;

  void iterativeInorderWalk() const;
  void iterativeInorderWalkQueue() const;
  void iterativeInorderWalkStack() const;

  void inorderWalk();

  void swap(BinarySearchTree<T>& src);

private:

  struct Node
  {
    T key_;
    Node* left_;
    Node* right_;
    Node* parent_;

    Node(const T& key):
      key_(key)
    {
      left_ = nullptr;
      right_ = nullptr;
      parent_ = nullptr;
    }

    ~Node()
    {
      left_ = nullptr;
      right_ = nullptr;
      parent_ = nullptr;
    }

  };

  Node* root_;

  void deleteSubtree(Node* node);

  Node* iterativeSearchNode(const T& key) const;

  void printNode(std::ostream& out, Node* root) const;

  int getCountSubTree(const Node* node) const;

  int getHeightSubTree(Node* node) const;

  void inorderWalk(Node* node) const;

};

template<class T>
BinarySearchTree<T>::BinarySearchTree():
root_(nullptr)
{
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(const T &root)
{
  root_ = new Node(root);
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree &&src) noexcept :
root_(src.root_)
{
  src.root_ = nullptr;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  deleteSubtree(root_);
}

template<class T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(BinarySearchTree &&src) noexcept
{
  root_ = src.root_;
  src.root_ = nullptr;
}

template<class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree &src)
{
  Node* nodeFirst = root_;
  Node* nodeSecond = src.root_;

  while (nodeFirst->left_)
  {
    nodeFirst = nodeFirst->left_;
  }

  while (nodeSecond->left_)
  {
    nodeSecond = nodeSecond->left_;
  }

  while (nodeFirst || nodeSecond)
  {
    if((!nodeFirst) || (!nodeSecond) || (nodeSecond->key_ != nodeFirst->key_))
    {
      return false;
    }

    if(nodeFirst->right_)
    {
      nodeFirst = nodeFirst->right_;
      while (nodeFirst->left_)
      {
        nodeFirst = nodeFirst->left_;
      }
    }
    else if(!nodeFirst->parent_)
    {
      break;
    }
    else if(nodeFirst->parent_->key_ > nodeFirst->key_)
    {
      nodeFirst = nodeFirst->parent_;
    }
    else if(nodeFirst->parent_->key_ < nodeFirst->key_)
    {
      while ((nodeFirst->parent_->key_ < nodeFirst->key_))
      {
        nodeFirst = nodeFirst->parent_;
        if (!nodeFirst->parent_)
        {
          break;
        }
      }
      if (nodeFirst)
      {
        nodeFirst = nodeFirst->parent_;
      }
    }

    if(nodeSecond->right_)
    {
      nodeSecond = nodeSecond->right_;
      while (nodeSecond->left_)
      {
        nodeSecond = nodeSecond->left_;
      }
    }
    else if(!nodeSecond->parent_)
    {
      break;
    }
    else if(nodeSecond->parent_->key_ > nodeSecond->key_)
    {
      nodeSecond = nodeSecond->parent_;
    }
    else if(nodeSecond->parent_->key_ < nodeSecond->key_)
    {
      while ((nodeSecond->parent_->key_ < nodeSecond->key_))
      {
        nodeSecond = nodeSecond->parent_;
        if (!nodeSecond->parent_)
        {
          break;
        }
      }
      if (nodeSecond)
      {
        nodeSecond = nodeSecond->parent_;
      }
    }

  }

  return true;
}

template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T &key) const
{
  return iterativeSearchNode(key);
}

template<class T>
bool BinarySearchTree<T>::insert(const T &key)
{
  if(iterativeSearch(key))
  {
    return 0;
  }
  else
  {
    if(!root_)
    {
      root_ = new Node(key);
      return 1;
    }
    Node* currNode = root_;
    while (true)
    {
      if(currNode->key_ > key && currNode->left_)
      {
        currNode = currNode->left_;
      }
      else if(currNode->key_ > key && !currNode->left_)
      {
        Node* newNode = new Node(key);
        newNode->parent_ = currNode;
        currNode->left_ = newNode;
        break;
      }
      else if(currNode->key_ < key && currNode->right_)
      {
        currNode = currNode->right_;
      }
      else if(currNode->key_ < key && !currNode->right_)
      {
        Node* newNode = new Node(key);
        newNode->parent_ = currNode;
        currNode->right_ = newNode;
        break;
      }
    }

    return 1;
  }
}

template<class T>
bool BinarySearchTree<T>::deleteItem(const T &key)
{
  Node* target = iterativeSearchNode(key);
  if(!target)
  {
    return false;
  }

  if(!target->left_ && !target->right_)
  {
    if(target->parent_->key_ > target->key_)
    {
      target->parent_->left_ = nullptr;
    }
    else
    {
      target->parent_->right_ = nullptr;
    }
    delete target;
  }
  else if((target->left_ && !target->right_) || (!target->left_ && target->right_))
  {
    if(target->parent_->key_ > target->key_)
    {
      if(target->right_)
      {
        target->parent_->left_ = target->right_;
        target->right_->parent_ = target->parent_;
      }
      else
      {
        target->parent_->left_ = target->left_;
        target->left_->parent_ = target->parent_;
      }
    }
    else
    {
      if(target->right_)
      {
        target->parent_->right_ = target->right_;
        target->right_->parent_ = target->parent_;
      }
      else
      {
        target->parent_->right_ = target->left_;
        target->left_->parent_ = target->parent_;
      }
    }
    delete target;
  }
  else
  {
    Node* minRight = target->right_;
    while (minRight->left_)
    {
      minRight = minRight->left_;
    }
    T temp = minRight->key_;
    deleteItem(minRight->key_);
    target->key_ = temp;
  }

  return true;
}

template<class T>
void BinarySearchTree<T>::print() const
{
  printNode(std::cout, root_);
}

template<class T>
int BinarySearchTree<T>::getCount() const
{
  return getCountSubTree(root_);
}

template<class T>
int BinarySearchTree<T>::getHeight() const
{
  return (getHeightSubTree(root_) - 1);
}

template<class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
  Node* currNode = root_;
  while (currNode->left_)
  {
    currNode = currNode->left_;
  }

  while (currNode)
  {
    std::cout << currNode->key_ << " ";
    if(currNode->right_)
    {
      currNode = currNode->right_;
      while (currNode->left_)
      {
        currNode = currNode->left_;
      }
    }
    else if(!currNode->parent_)
    {
      break;
    }
    else if(currNode->parent_->key_ > currNode->key_)
    {
      currNode = currNode->parent_;
    }
    else if(currNode->parent_->key_ < currNode->key_)
    {
      while ((currNode->parent_->key_ < currNode->key_))
      {
        currNode = currNode->parent_;
        if (!currNode->parent_)
        {
          break;
        }
      }
      if (currNode)
      {
        currNode = currNode->parent_;
      }
    }
  }
}

template<class T>
void BinarySearchTree<T>::inorderWalk()
{
  inorderWalk(root_);
}

template<class T>
void BinarySearchTree<T>::deleteSubtree(BinarySearchTree::Node *node)
{
  if(!node)
  {
    return;
  }
  if (!node->right_ && !node->left_)
  {
    delete node;
  }
  else if(!node->left_)
  {
    deleteSubtree(node->right_);
    delete node;
  }
  else if(!node->right_)
  {
    deleteSubtree(node->left_);
    delete node;
  }
  else
  {
    deleteSubtree(node->left_);
    deleteSubtree(node->right_);
    delete node;
  }
}

template<class T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::iterativeSearchNode(const T &key) const
{
  Node* currNode = root_;
  while (currNode)
  {
    if(currNode->key_ > key)
    {
      currNode = currNode->left_;
    }
    else if(currNode->key_ < key)
    {
      currNode = currNode->right_;
    }
    else if(currNode->key_ == key)
    {
      break;
    }
  }

  return currNode;
}

template<class T>
int BinarySearchTree<T>::getCountSubTree(const BinarySearchTree::Node *node) const
{
  if (node)
  {
    return 1 + getCountSubTree(node->left_) + getCountSubTree(node->right_);
  }
  else
  {
    return 0;
  }
}

template<class T>
int BinarySearchTree<T>::getHeightSubTree(BinarySearchTree::Node *node) const
{
  if(node)
  {
    return 1 + std::max(getHeightSubTree(node->left_), getHeightSubTree(node->right_));
  }
  else
  {
    return 0;
  }
}

template<class T>
void BinarySearchTree<T>::inorderWalk(BinarySearchTree::Node *node) const
{
  if(node->left_) inorderWalk(node->left_);
  std::cout << node->key_ << " ";
  if(node->right_) inorderWalk(node->right_);
}

template<class T>
void BinarySearchTree<T>::printNode(std::ostream &out, Node *root) const
{
  out << "( ";
  if(root->left_) printNode(out, root->left_);
  out << root->key_ << " ";
  if(root->right_) printNode(out, root->right_);
  out << ") ";
}

template<class T>
void BinarySearchTree<T>::swap(BinarySearchTree<T> &src)
{
  Node* temp = src.root_;
  src.root_ = this->root_;
  this->root_ = temp;
}

template<class T>
void BinarySearchTree<T>::iterativeInorderWalkQueue() const
{
  QueueArray<Node*> queue(getCount());
  queue.enQueue(root_);
  while (!queue.isEmpty())
  {
    size_t temp = queue.getSize();
    for (size_t i = 0; i < temp; ++i)
    {
      Node* tempNode = queue.deQueue();
      std::cout << tempNode->key_ << " ";
      if(tempNode->left_)
      {
        queue.enQueue(tempNode->left_);
      }
      if(tempNode->right_)
      {
        queue.enQueue(tempNode->right_);
      }
    }
  }
}

template<class T>
void BinarySearchTree<T>::iterativeInorderWalkStack() const
{
  StackArray<Node*> stack(getCount());
  Node*temp = root_;
  while (temp->left_)
  {
    stack.push(temp);
    temp = temp->left_;
  }
  stack.push(temp);
  while (!stack.isEmpty())
  {
    temp = stack.pop();
    std::cout << temp->key_ << " ";
    if(temp->right_)
    {
      temp = temp->right_;
      stack.push(temp);
      while (temp->left_)
      {
        temp = temp->left_;
        stack.push(temp);
      }
    }
  }
}

#endif //INC_4_1_BINARYTREE_BINARYSEARCHTREE_HPP
