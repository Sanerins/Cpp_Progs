#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree():
  root_(nullptr)
{
}


BinarySearchTree::BinarySearchTree(const string &root)
{
  root_ = new Node(root);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree &&src) noexcept :
  root_(src.root_)
{
  src.root_ = nullptr;
}


BinarySearchTree::~BinarySearchTree()
{
  deleteSubtree(root_);
}


BinarySearchTree &BinarySearchTree::operator=(BinarySearchTree &&src) noexcept
{
  root_ = src.root_;
  src.root_ = nullptr;
  return *this;
}


bool BinarySearchTree::operator==(const BinarySearchTree &src)
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


bool BinarySearchTree::iterativeSearch(const string &key) const
{
  return iterativeSearchNode(key);
}


bool BinarySearchTree::insert(const string &key)
{
  if(iterativeSearch(key))
  {
    iterativeSearchNode(key)->data_ += 1;
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


bool BinarySearchTree::deleteItem(const string &key)
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
    string temp = minRight->key_;
    deleteItem(minRight->key_);
    target->key_ = temp;
  }

  return true;
}


void BinarySearchTree::print() const
{
  printNode(std::cout, root_);
}


int BinarySearchTree::getCount() const
{
  return getCountSubTree(root_);
}


int BinarySearchTree::getHeight() const
{
  return (getHeightSubTree(root_) - 1);
}


void BinarySearchTree::iterativeInorderWalk() const
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


void BinarySearchTree::inorderWalk()
{
  inorderWalk(root_);
}


void BinarySearchTree::deleteSubtree(BinarySearchTree::Node *node)
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


typename BinarySearchTree::Node *BinarySearchTree::iterativeSearchNode(const string &key) const
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


int BinarySearchTree::getCountSubTree(const BinarySearchTree::Node *node) const
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


int BinarySearchTree::getHeightSubTree(BinarySearchTree::Node *node) const
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


void BinarySearchTree::inorderWalk(BinarySearchTree::Node *node) const
{
  if(node->left_) inorderWalk(node->left_);
  std::cout << node->key_ << " ";
  if(node->right_) inorderWalk(node->right_);
}


void BinarySearchTree::printNode(std::ostream &out, Node *root) const
{
  out << "( ";
  if(root->left_) printNode(out, root->left_);
  out << root->key_ << " ";
  if(root->right_) printNode(out, root->right_);
  out << ") ";
}


void BinarySearchTree::swap(BinarySearchTree &src)
{
  Node* temp = src.root_;
  src.root_ = this->root_;
  this->root_ = temp;
}

std::multimap<int, string> BinarySearchTree::getFrequency() const
{
  std::multimap<int, string> pairs;
  getFrequency(root_, pairs);
  return pairs;
}

void BinarySearchTree::getFrequency(BinarySearchTree::Node *node, multimap<int, std::string> &pairs) const
{
  pairs.insert({node->data_, node->key_});
  if(node->left_)
    getFrequency(node->left_, pairs);
  if(node->right_)
    getFrequency(node->right_, pairs);
}
