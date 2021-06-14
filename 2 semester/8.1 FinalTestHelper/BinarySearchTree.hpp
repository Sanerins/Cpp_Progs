#ifndef TREE_BINARYSEARCHTREE_HPP
#define TREE_BINARYSEARCHTREE_HPP

#include <iostream>
#include <vector>
#include "StackArray.hpp"
#include "QueueArray.hpp"

template<class T>
class BinarySearchTree
{
public:

  BinarySearchTree();

  BinarySearchTree(const BinarySearchTree<T> &scr) = delete;

  BinarySearchTree(BinarySearchTree<T> &&scr) noexcept;

  BinarySearchTree<T> &operator=(const BinarySearchTree<T> &src) = delete;

  BinarySearchTree<T> &operator=(BinarySearchTree<T> &&src) noexcept;

  // Деструктор освобождает память, занятую узлами дерева
  ~BinarySearchTree();

  // 1.1 Функция поиска по ключу в бинарном дереве поиска
  bool iterativeSearch(const T &key) const;

  // 2 Вставка нового элемента в дерево:
  bool insert(const T &key);
  void insert(const std::vector<T> &vector)
  {
    for (auto & i: vector)
    {
      insert(i);
    }
  }

  // 3.1 Удаление элемента из дерева, не нарушающее порядка элементов
  bool deleteKey(const T &key);

  // 4.1 Печать строкового изображения дерева в выходной поток out
  void print(std::ostream &out) const;

  // 5.1 Определение количества узлов дерева
  int getCount() const;

  // 6.1 Определение высоты дерева
  int getHeight() const;

  // 7 Инфиксный обход дерева (итеративный)
  void iterativeInorderWalk(void (*visit)(T)) const;

  // 8.1 Инфиксный обход дерева (рекурсивный)
  void inorderWalk(void (*visit)(T)) const;
  void inorderWalkFromDown(void (*visit)(T)) const;

  void inorderWalk(void (std::vector<T>::*visit)(const T &), std::vector<T> &a);

  void inorderStackWalk(void (*func)(T), size_t size = 40) const;

  void bfs(void (*func)(T), size_t size = 40) const;

  // 9 Сравнение деревьев: true, если все узлы деревьев одинаковые
  bool operator==(const BinarySearchTree<T> &src);

private:

  // Описание структуры узла со ссылками на детей и родителя
  struct Node
  {
    T key_;         // значение ключа, содержащееся в узле
    Node *left_;     // указатель на левое поддерево
    Node *right_;    // указатель на правое поддерево
    Node *p_;        // указатель на  родителя

    explicit Node(T key, Node *left = nullptr, Node *right = nullptr, Node *p = nullptr):
      key_(key),
      left_(left),
      right_(right),
      p_(p)
    {}
  };

  // Дерево реализовано в виде указателя на корневой узел.
  Node *root_;

  void swap(BinarySearchTree<T> &left, BinarySearchTree<T> &right);

  // Рекурсивная функция для освобождения памяти
  void deleteSubtree(Node *node);

  // 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
  Node *iterativeSearchNode(const T &key) const;

  // 4.2 Рекурсивная функция для вывода изображения дерева в выходной поток
  void printNode(std::ostream &out, Node *root) const;

  // 5.2 Рекурсивная функция определения количества узлов дерева
  int getCountSubTree(const Node *node) const;

  // 6.2 Рекурсивная функция определения высоты дерева
  int getHeightSubTree(Node *node) const;

  void inorderWalkNode(Node *node, void (*visit)(T)) const;

  void inorderWalkNodeFromDown(Node *node, void (*visit)(T)) const;

  void inorderWalkNode(Node *node, void (std::vector<T>::*visit)(const T &), std::vector<T> &a) const;

  void inorderStackWalkPrivate(Node *node, void (*func)(T), size_t size) const;

  void BFS(Node *node, void (*func)(T), size_t size) const;

};

// Конструктор "по умолчанию" создает пустое дерево
template<class T>
BinarySearchTree<T>::BinarySearchTree():
  root_(nullptr)
{}

template<class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T> &&scr) noexcept
{
  swap(*this, scr);
  scr.root_ = nullptr;
}

// .........................................................................
template<class T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(BinarySearchTree<T> &&src) noexcept
{
  if (this != &src)
  {
    deleteSubtree(this->root_);
    swap(*this, src);
    src.root_ = nullptr;
  }
  return *this;
}

// .........................................................................
// Деструктор освобождает память, занятую узлами дерева

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  deleteSubtree(this->root_);
}

// Рекурсивная функция для освобождения памяти
template<class T>
void BinarySearchTree<T>::deleteSubtree(Node *node)
{
  if (node != nullptr)
  {
    if (node->right_ != nullptr)
    {
      deleteSubtree(node->right_);
    }
    if (node->left_ != nullptr)
    {
      deleteSubtree(node->left_);
    }
    delete node;
  }
}

// .........................................................................
template<class T>
void BinarySearchTree<T>::swap(BinarySearchTree<T> &left, BinarySearchTree<T> &right)
{
  std::swap(left.root_, right.root_);
}
// .........................................................................

// 1.1 Функция поиска по ключу в бинарном дереве поиска
template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T &key) const
{
  return (iterativeSearchNode(key) != nullptr);
}

// 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
template<class T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::iterativeSearchNode(const T &key) const
{
  Node *current = root_;
  while (current != nullptr)
  {
    if (current->key_ < key)
    {
      current = current->right_;
    }
    else if (current->key_ > key)
    {
      current = current->left_;
    }
    else
    {
      return current;
    }
  }
  return current;

}
// .........................................................................

// 2. Вставка нового элемента в дерево:
// true,если элемент добавлен; false, если элемент уже был

template<class T>
bool BinarySearchTree<T>::insert(const T &key)
{
  Node *current = root_;
  Node *parent = nullptr;
  while (current != nullptr)
  {
    parent = current;
    if (current->key_ < key)
    {
      current = current->right_;
      if (current == nullptr)
      {
        current = new Node(key);
        current->p_ = parent;
        parent->right_ = current;
        break;
      }
    }
    else if (current->key_ > key)
    {
      current = current->left_;
      if (current == nullptr)
      {
        current = new Node(key);
        current->p_ = parent;
        parent->left_ = current;
        break;
      }
    }
    else
    {
      return false;
    }
  }

  if (root_ == nullptr)
  {
    current = new Node(key);
    root_ = current;
  }

  return true;
}
// .........................................................................

// 3. Удаление элемента из дерева, не нарушающее порядка элементов
template<class T>
bool BinarySearchTree<T>::deleteKey(const T &key)
{
  Node *current = iterativeSearchNode(key);
  if (current == nullptr)
  {
    return false;
  }
  else if (current == root_ && current->left_ == nullptr && current->right_ == nullptr)
  {
    delete root_;
    root_ = nullptr;
    return true;
  }
  if (current->right_ && current->left_)
  {
    Node *temp = current;
    current = current->right_;
    if (current->left_)
    {
      while (current->left_)
      {
        current = current->left_;
      }
      temp->key_ = current->key_;
      if (current->right_ != nullptr)
      {
        Node *toDelete = current;
        current = current->p_;
        current->left_ = toDelete->right_;
        toDelete->right_->p_ = current;
        delete toDelete;
        return true;
      }
      current = current->p_;
      delete current->left_;
      current->left_ = nullptr;
      return true;
    }
    else
    {
      temp->key_ = current->key_;
      Node *toDelete = temp->right_;
      if (temp->right_)
      {
        temp->right_ = temp->right_->right_;
        if (temp->right_)
        {
          temp->right_->p_ = temp;
        }
      }
      delete toDelete;
      return true;
    }
  }
  else if (current->right_)
  {
    Node *ptrToParent = current->p_;
    if (current != root_)
    {
      if (ptrToParent->right_ == current)
      {
        ptrToParent->right_ = current->right_;
        current->right_->p_ = ptrToParent;
      }
      else if (ptrToParent->left_ == current)
      {
        ptrToParent->left_ = current->right_;
        current->right_->p_ = ptrToParent;
      }
    }
    else
    {
      root_ = current->right_;
      root_->p_ = ptrToParent;
    }
    delete current;
    return true;
  }
  else if (current->left_)
  {
    Node *ptrToParent = current->p_;
    if (current != root_)
    {
      if (ptrToParent->right_ == current)
      {
        ptrToParent->right_ = current->left_;
        current->left_->p_ = ptrToParent;
      }
      else if (ptrToParent->left_ == current)
      {
        ptrToParent->left_ = current->left_;
        current->left_->p_ = ptrToParent;
      }
    }
    else
    {
      root_ = current->left_;
      root_->p_ = ptrToParent;
    }
    delete current;
    return true;
  }
  else
  {
    Node *ptrToParent = current->p_;
    if (current != root_)
    {
      if (ptrToParent->right_ == current)
      {
        ptrToParent->right_ = current->left_;
      }
      else if (ptrToParent->left_ == current)
      {
        ptrToParent->left_ = current->left_;
      }
    }
    delete current;
    current = nullptr;
    return true;
  }
  return false;
}
// .........................................................................

// 4.1 Печать строкового изображения дерева в выходной поток out
template<class T>
void BinarySearchTree<T>::print(std::ostream &out) const
{
  printNode(out, root_);
  out << std::endl;
}

// 4.2 Рекурсивная функция для вывода изображения дерева в выходной поток
template<class T>
void BinarySearchTree<T>::printNode(std::ostream &out, Node *root) const
{
  // Изображение дерева заключается в круглые скобки.
  out << '(';
  if (root != nullptr)
  {
    // Для узлов дерева должна быть определена (или переопределена)
    // операция вывода в выходной поток <<
    out << root->key_;
    printNode(out, root->left_);
    printNode(out, root->right_);
  }
  out << ')';
}
// .........................................................................

//5.1 Определение количества узлов дерева
template<class T>
int BinarySearchTree<T>::getCount() const
{
  return getCountSubTree(this->root_);
}

// 5.2 Рекурсивная функция определения количества узлов дерева
template<class T>
int BinarySearchTree<T>::getCountSubTree(const Node *node) const
{
  if (node == nullptr)
  {
    return 0;
  }
  return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}
// .........................................................................

// 6.1 Определение высоты дерева
template<class T>
int BinarySearchTree<T>::getHeight() const
{
  return getHeightSubTree(this->root_);
}

// 6.2 Рекурсивная функция определения высоты дерева
template<class T>
int BinarySearchTree<T>::getHeightSubTree(Node *node) const
{
  int temp, tempRight;
  if (node->left_ != nullptr)
  {
    temp = 1 + getHeightSubTree(node->left_);
  }
  else
  {
    temp = 1;
  }
  if (node->right_ != nullptr)
  {
    tempRight = 1 + getHeightSubTree(node->right_);
  }
  else
  {
    tempRight = 1;
  }
  return std::max(temp, tempRight);
}

// .........................................................................

// 7. Инфиксный обход дерева (итеративный)
template<class T>
void BinarySearchTree<T>::iterativeInorderWalk(void (*visit)(T)) const
{
  T prev;
  Node *max = root_;
  Node *min = root_;
  while (max->right_ != nullptr)
  {
    max = max->right_;
  }
  while (min->left_ != nullptr)
  {
    min = min->left_;
  }
  prev = min->key_;
  Node *current = min;
  visit(prev);
  while (prev != max->key_)
  {
    while (current->left_ != nullptr && current->left_->key_ > prev)
    {
      current = current->left_;
    }
    if (current->left_ != nullptr && current->left_->key_ < prev && prev != current->key_)
    {
      if (current->left_->key_ < prev and prev != current->key_)
      {
        if (prev != current->key_)
        {
          visit(current->key_);
          prev = current->key_;
        }
      }
    }
    else
    {
      if (current->right_ != nullptr)
      {
        if (prev != current->key_)
        {
          visit(current->key_);
          prev = current->key_;
        }
        current = current->right_;
      }
      else
      {
        if (prev != current->key_)
        {
          visit(current->key_);
          prev = current->key_;
        }
        while (current->key_ <= prev and prev != max->key_)
        {
          current = current->p_;
        }
      }
    }
  }
}
// .........................................................................

// 8.1 Инфиксный обход дерева (рекурсивный)
template<class T>
void BinarySearchTree<T>::inorderWalk(void (*visit)(T)) const
{
  return inorderWalkNode(this->root_, visit);
}
template<class T>
void BinarySearchTree<T>::inorderWalkFromDown(void (*visit)(T)) const
{
  return inorderWalkNodeFromDown(this->root_, visit);
}

template<class T>
void BinarySearchTree<T>::inorderWalk(void (std::vector<T>::*visit)(const T &), std::vector<T> &a)
{
  return inorderWalkNode(this->root_, visit, a);
}

// 8.2 Рекурсивная функция для организации обхода узлов дерева.
template<class T>
void BinarySearchTree<T>::inorderWalkNode(Node *node, void (*visit)(T)) const
{
  if (node != nullptr)
  {
    (*visit)(node->key_);
    inorderWalkNode(node->left_, visit);
    inorderWalkNode(node->right_, visit);
  }
}
template<class T>
void BinarySearchTree<T>::inorderWalkNodeFromDown(Node *node, void (*visit)(T)) const
{
  if (node != nullptr)
  {
    inorderWalkNodeFromDown(node->left_, visit);
    inorderWalkNodeFromDown(node->right_, visit);
    (*visit)(node->key_);
  }
}

template<class T>
void BinarySearchTree<T>::inorderWalkNode(Node *node, void (std::vector<T>::*visit)(const T &), std::vector<T> &a) const
{
  if (node != nullptr)
  {
    inorderWalkNode(node->left_, visit, a);
    (a.*visit)(node->key_);
    inorderWalkNode(node->right_, visit, a);
  }
}

// .........................................................................
// 9. Сравнение деревьев: true, если все узлы деревьев одинаковые
template<class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree<T> &src)
{
  std::vector<T> a;
  inorderWalk(&std::vector<T>::push_back, a); // вставка элементов в вектор по возрастанию
  for (long unsigned int i = 0; i < a.size(); ++i)
  {
    if (!src.iterativeSearch(a[i]))
    {
      return false;
    }
  }
  return true;
}

template<class T>
void BinarySearchTree<T>::bfs(void (*func)(T), size_t size) const
{
  BFS(root_, func, size);
}

template<typename T>
void BinarySearchTree<T>::BFS(BinarySearchTree<T>::Node *node, void (*func)(T), size_t size) const
{
  QueueArray<Node *> q(size);
  q.enQueue(node);
  Node *tmp;
  while (!q.isEmpty() && (node != nullptr))
  {
    tmp = q.deQueue();
    func(tmp->key_);
    if (tmp->left_ != nullptr)
    {
      q.enQueue(tmp->left_);
    }
    if (tmp->right_ != nullptr)
    {
      q.enQueue(tmp->right_);
    }
  }
}

template<class T>
void BinarySearchTree<T>::inorderStackWalk(void (*func)(T), size_t size) const
{
  inorderStackWalkPrivate(root_, func, size);
}

template<class T>
void BinarySearchTree<T>::inorderStackWalkPrivate(BinarySearchTree<T>::Node *node, void (*func)(T), size_t size) const
{
  StackArray<Node *> stack(size);
  while (!stack.isEmpty() || node != nullptr)
  {
    if (node != nullptr)
    {
      stack.push(node);
      node = node->left_;
    }
    else
    {
      node = stack.pop();
      func(node->key_);
      node = node->right_;
    }
  }
}

#endif //TREE_BINARYSEARCHTREE_HPP
