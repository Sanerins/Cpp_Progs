#ifndef INC_4_1_BINARYTREE_BINARYSEARCHTREE_HPP
#define INC_4_1_BINARYTREE_BINARYSEARCHTREE_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class BinarySearchTree
{
public:

  BinarySearchTree();
  BinarySearchTree(const string& root);
  BinarySearchTree(const BinarySearchTree& src) = delete;
  BinarySearchTree(BinarySearchTree&& src) noexcept;

  ~BinarySearchTree();

  BinarySearchTree& operator=(const BinarySearchTree& src) = delete;
  BinarySearchTree& operator=(BinarySearchTree&& src) noexcept;

  bool operator==(const BinarySearchTree& src);

  bool iterativeSearch(const string& key) const;

  bool insert(const string& key);

  bool deleteItem(const string& key);

  void print() const;

  int getCount() const;

  int getHeight() const;

  void iterativeInorderWalk() const;

  void inorderWalk();

  std::multimap<int, string> getFrequency() const;

  void swap(BinarySearchTree& src);

private:

  struct Node
  {
    string key_;
    int data_;
    Node* left_;
    Node* right_;
    Node* parent_;

    Node(const string& key):
      key_(key),
      data_(1)
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

  Node* iterativeSearchNode(const string& key) const;

  void printNode(std::ostream& out, Node* root) const;

  int getCountSubTree(const Node* node) const;

  int getHeightSubTree(Node* node) const;

  void inorderWalk(Node* node) const;

  void getFrequency(Node* node, multimap<int, std::string> &pairs) const;

};

#endif //INC_4_1_BINARYTREE_BINARYSEARCHTREE_HPP
