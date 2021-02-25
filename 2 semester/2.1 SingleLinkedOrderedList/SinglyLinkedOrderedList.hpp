#ifndef INC_2_1_SINGLELINKEDORDEREDLIST_SINGLYLINKEDORDEREDLIST_HPP
#define INC_2_1_SINGLELINKEDORDEREDLIST_SINGLYLINKEDORDEREDLIST_HPP
#include <iostream>

class SinglyLinkedOrderedList
{
public:

  SinglyLinkedOrderedList();

  ~SinglyLinkedOrderedList();

  SinglyLinkedOrderedList& operator=(const SinglyLinkedOrderedList& src);

  SinglyLinkedOrderedList& operator=(SinglyLinkedOrderedList&& src);

  friend std::ostream &operator<<(std::ostream& out, SinglyLinkedOrderedList& src);

  bool Search(const int &item) const;

  bool Insert(const int &item);

  bool Delete(const int &item);

  bool Combine(SinglyLinkedOrderedList *src);

  bool Exclude(SinglyLinkedOrderedList *src);

  bool Intersect(SinglyLinkedOrderedList *src);

  bool Show();

private:
  struct Node
  {
    int item_;
    Node *next_;

    Node(int item = 0, Node *next = nullptr):
      item_(item),
      next_(next)
    {
    }
  };

  Node *head_;

  Node *SearchNode(const int &item, Node *startingNode = nullptr) const;

  bool Insert(Node *item, Node *startingNode = nullptr);

  bool Delete(Node *item);

  Node *Minimun() const;

  Node *Maximum() const;

  Node *Successor(const int item) const;

  Node *Predecessor(const int item, Node *startingNode = nullptr) const;

  void Purify();
};

#endif //INC_2_1_SINGLELINKEDORDEREDLIST_SINGLYLINKEDORDEREDLIST_HPP
