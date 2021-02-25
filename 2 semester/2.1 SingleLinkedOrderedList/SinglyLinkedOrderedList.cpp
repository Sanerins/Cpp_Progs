#include "SinglyLinkedOrderedList.hpp"

SinglyLinkedOrderedList::SinglyLinkedOrderedList()
{
  head_ = nullptr;
}

SinglyLinkedOrderedList &SinglyLinkedOrderedList::operator=(const SinglyLinkedOrderedList &src)
{
  if (src.head_ == nullptr)
  {
    head_ = nullptr;
    return *this;
  }
  if (head_ != nullptr)
  {
    Purify();
  }
  head_ = new Node(src.head_->item_);
  Node *current = head_;
  Node *srcCurrent = src.head_;
  while (srcCurrent->next_ != nullptr)
  {
    current->next_ = new Node(srcCurrent->next_->item_);
    current = current->next_;
    srcCurrent = srcCurrent->next_;
  }
  return *this;
}

SinglyLinkedOrderedList &SinglyLinkedOrderedList::operator=(SinglyLinkedOrderedList &&src)
{
  if (src.head_ == nullptr)
  {
    head_ = nullptr;
    return *this;
  }
  if (head_ != nullptr)
  {
    Purify();
  }
  head_ = src.head_;
  src.head_ = nullptr;
  return *this;
}

std::ostream &operator<<(std::ostream &out, SinglyLinkedOrderedList &src)
{
  SinglyLinkedOrderedList::Node *temp = src.head_;
  while (temp != nullptr)
  {
    out << temp->item_ << " ";
    temp = temp->next_;
  }
  return out;
}

bool SinglyLinkedOrderedList::Search(const int &item) const
{
  return (SearchNode(item));
}

bool SinglyLinkedOrderedList::Insert(const int &item)
{
  Node *temp = new Node;
  temp->item_ = item;
  return (Insert(temp));
}

bool SinglyLinkedOrderedList::Delete(const int &item)
{
  return (Delete(SearchNode(item)));
}

bool SinglyLinkedOrderedList::Combine(SinglyLinkedOrderedList *src)
{
  Node *startingNode = nullptr;
  Node *curr = nullptr;
  while (src->head_ != nullptr)
  {
    curr = src->head_;
    startingNode = Predecessor(curr->item_, startingNode);
    if (startingNode != nullptr)
    {
      if (startingNode->next_ == nullptr)
      {
        startingNode->next_ = src->head_;
        break;
      }
    }
    src->head_ = src->head_->next_;
    Insert(curr, startingNode);
  }
  src->head_ = nullptr;
  return 1;
}

bool SinglyLinkedOrderedList::Exclude(SinglyLinkedOrderedList *src)
{
  Node *startingNode = nullptr;
  Node *curr = src->head_;
  Node *arr;
  while (curr != nullptr)
  {
    startingNode = Predecessor(curr->item_, startingNode);
    if (startingNode != nullptr)
    {
      if (startingNode->next_ == nullptr)
      {
        break;
      }
    }
    arr = SearchNode(curr->item_, startingNode);
    if (arr != nullptr)
    {
      Delete(arr);
    }
    curr = curr->next_;
  }
  src->Purify();
  return 1;
}

bool SinglyLinkedOrderedList::Intersect(SinglyLinkedOrderedList *src)
{
  Node *startingNode = nullptr;
  Node *curr = nullptr;
  Node *temp = head_;
  while (temp != nullptr)
  {
    curr = temp;
    temp = temp->next_;
    startingNode = src->Predecessor(curr->item_, startingNode);
    if (startingNode != nullptr)
    {
      if (startingNode->next_ == nullptr)
      {
        while (temp != nullptr)
        {
          Delete(curr);
          curr = temp;
          temp = temp->next_;
        }
        break;
      }
    }
    if (!src->SearchNode(curr->item_, startingNode))
    {
      Delete(curr);
    }
  }
  src->Purify();
  return 1;
}

bool SinglyLinkedOrderedList::Show()
{
  Node *temp = head_;
  while (temp != nullptr)
  {
    std::cout << temp->item_ << " ";
    temp = temp->next_;
  }
  std::cout << '\n';
  return 1;
}

SinglyLinkedOrderedList::~SinglyLinkedOrderedList()
{
  Node *temp = head_;
  Node *curr = nullptr;
  while (temp != nullptr)
  {
    curr = temp;
    temp = temp->next_;
    delete curr;
  }
}

SinglyLinkedOrderedList::Node *SinglyLinkedOrderedList::SearchNode(const int &item, Node *startingNode) const
{
  Node *temp;
  if (startingNode == nullptr)
  {
    temp = head_;
  }
  else
  {
    temp = startingNode;
  }
  while (temp != nullptr and temp->item_ <= item)
  {
    if (temp->item_ == item)
    {
      return temp;
    }
    temp = temp->next_;
  }
  return (nullptr);
}

bool SinglyLinkedOrderedList::Insert(Node *item, Node *startingNode)
{
  if (head_ == nullptr)
  {
    head_ = item;
  }
  else
  {
    Node *predecessor = Predecessor(item->item_, startingNode);
    if (predecessor == nullptr)
    {
      if (startingNode == nullptr)
      {
        if (head_->item_ == item->item_)
        {
          delete item;
          item = head_;
          return 0;
        }
        item->next_ = head_;
        head_ = item;
      }
      else
      {
        if (startingNode->item_ == item->item_)
        {
          delete item;
          item = startingNode;
          return 0;
        }
        item->next_ = startingNode;
        Predecessor(startingNode->item_)->next_ = item;
      }
    }
    else if (predecessor->next_ == nullptr)
    {
      predecessor->next_ = item;
      item->next_ = nullptr;
    }
    else if (predecessor->next_->item_ == item->item_)
    {
      delete item;
      item = predecessor->next_;
      return 0;
    }
    else
    {
      item->next_ = predecessor->next_;
      predecessor->next_ = item;
    }
  }
  return 1;
}

bool SinglyLinkedOrderedList::Delete(Node *item)
{
  if (head_ == nullptr)
  {
    return 0;
  }
  else
  {
    if (!Search(item->item_))
    {
      return 0;
    }
    Node *predecessor = Predecessor(item->item_);
    if (predecessor == nullptr)
    {
      head_ = head_->next_;
    }
    else if (item->next_ == nullptr)
    {
      predecessor->next_ = nullptr;
    }
    else
    {
      predecessor->next_ = item->next_;
    }
    delete item;
  }
  return 1;
}

SinglyLinkedOrderedList::Node *SinglyLinkedOrderedList::Minimun() const
{
  return (head_);
}

SinglyLinkedOrderedList::Node *SinglyLinkedOrderedList::Maximum() const
{
  Node *temp = head_;
  while (temp->next_ != nullptr)
  {
    temp = temp->next_;
  }
  return (temp);
}

SinglyLinkedOrderedList::Node *SinglyLinkedOrderedList::Successor(const int item) const
{
  Node *temp = head_;
  while (temp != nullptr)
  {
    if (temp->item_ > item)
    {
      return temp;
    }
    temp = temp->next_;
  }
  return (nullptr);
}

SinglyLinkedOrderedList::Node *SinglyLinkedOrderedList::Predecessor(const int item, Node *startingNode) const
{
  Node *temp;
  if (startingNode == nullptr)
  {
    temp = head_;
  }
  else
  {
    temp = startingNode;
  }

  if (temp->item_ >= item)
  {
    return (nullptr);
  }
  while (temp->next_ != nullptr)
  {
    if (temp->item_ < item and temp->next_->item_ >= item)
    {
      return temp;
    }
    temp = temp->next_;
  }
  return (temp);
}

void SinglyLinkedOrderedList::Purify()
{
  Node *temp = head_;
  Node *curr = nullptr;
  while (temp != nullptr)
  {
    curr = temp;
    temp = temp->next_;
    delete curr;
  }
  head_ = nullptr;
}