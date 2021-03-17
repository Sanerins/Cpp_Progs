#ifndef INC_4_1_BINARYTREE_BINARYSEARCHTREE_HPP
#define INC_4_1_BINARYTREE_BINARYSEARCHTREE_HPP

template<class T>
class BinarySearchTree
{
public:

  BinarySearchTree();
  BinarySearchTree(const T& root);

  BinarySearchTree(const BinarySearchTree& src);
  BinarySearchTree(BinarySearchTree&& src);

  ~BinarySearchTree();

  BinarySearchTree<T>& operator=(const BinarySearchTree& src);
  BinarySearchTree<T>& operator=(BinarySearchTree&& src);

  bool operator==(const BinarySearchTree& src);

  bool iterativeSearch(const T& key) const;

  bool insert(const T& key);

  bool deleteItem(const T& key);

  void print() const;

  int getCount() const;

  int getHeight() const;

  void iterativeInorderWalk() const;

  void inorderWalk();

private:

  struct Node
  {
    T key_;
    Node* left_;
    Node* right_;
    Node* parent_;

    Node(T& key):
      key_(key)
    {
      left_ = nullptr;
      right_ = nullptr;
      parent_ = nullptr;
    }

  };

  Node* root;

  friend void swap(BinarySearchTree& first, BinarySearchTree& second);

  void deleteSubtree(Node* node);

  Node* iterativeSearchNode(const T& key) const;

  int getCountSubTree(const Node* node) const;

  int getHeightSubTree(Node* node) const;

  void inorderWalk(Node* node) const;

};

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{

}

template<class T>
BinarySearchTree<T>::BinarySearchTree(const T &root)
{

}

template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree &src)
{

}

template<class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree &&src)
{

}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{

}

template<class T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(const BinarySearchTree &src)
{
  return <#initializer#>;
}

template<class T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(BinarySearchTree &&src)
{
  return <#initializer#>;
}

template<class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree &src)
{
  return false;
}

template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T &key) const
{
  return false;
}

template<class T>
bool BinarySearchTree<T>::insert(const T &key)
{
  return false;
}

template<class T>
bool BinarySearchTree<T>::deleteItem(const T &key)
{
  return false;
}

template<class T>
void BinarySearchTree<T>::print() const
{

}

template<class T>
int BinarySearchTree<T>::getCount() const
{
  return 0;
}

template<class T>
int BinarySearchTree<T>::getHeight() const
{
  return 0;
}

template<class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{

}

template<class T>
void BinarySearchTree<T>::inorderWalk()
{

}

template<class T>
void BinarySearchTree<T>::deleteSubtree(BinarySearchTree::Node *node)
{

}

template<class T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::iterativeSearchNode(const T &key) const
{
  return nullptr;
}

template<class T>
int BinarySearchTree<T>::getCountSubTree(const BinarySearchTree::Node *node) const
{
  return 0;
}

template<class T>
int BinarySearchTree<T>::getHeightSubTree(BinarySearchTree::Node *node) const
{
  return 0;
}

template<class T>
void BinarySearchTree<T>::inorderWalk(BinarySearchTree::Node *node) const
{

}

#endif //INC_4_1_BINARYTREE_BINARYSEARCHTREE_HPP
