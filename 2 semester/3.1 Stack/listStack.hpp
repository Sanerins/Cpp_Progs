#ifndef INC_3_1_STACK_LISTSTACK_HPP
#define INC_3_1_STACK_LISTSTACK_HPP

#include "stack.hpp"
#include "Exceptions.hpp"

template<class T>
class StackList: public Stack<T>
{
public:

  StackList(const T &item)
  {
    head_ = new Node(item);
  }

  ~StackList()
  {
    Node *temp = head_;
    if(temp == nullptr)
    {
      return;
    }
    while (temp->next_ != nullptr)
    {
      temp = head_->next_;
      delete head_;
      head_ = temp;
    }
    delete head_;
  }

  void push(const T &src) override
  {
    Node* temp = head_;
    head_ = new Node(src);
    head_->next_ = temp;
  }

  T pop() override
  {
    if (isEmpty())
    {
      throw StackUnderflow("This stack is empty already. There is nothing to pop from it");
    }
    T temp = head_->item_;
    if (head_->next_ == nullptr)
    {
      delete head_;
      head_ = nullptr;
    }
    else
    {
      Node *tempNode = head_;
      head_ = head_->next_;
      delete tempNode;
    }
    return temp;
  }

  const T &peek() override
  {
    if (isEmpty())
    {
      throw StackUnderflow("This stack is empty.");
    }
    return head_->item_;
  }

  bool isEmpty() override
  {
    return (head_ == nullptr);
  }

private:
  struct Node
  {
    Node(const T &item)
    {
      next_ = nullptr;
      item_ = item;
    }

    ~Node()
    {
      next_ = nullptr;
      item_ = 0;
    }

    Node *next_;
    T item_;
  };

  Node *head_;
};

#endif //INC_3_1_STACK_LISTSTACK_HPP
