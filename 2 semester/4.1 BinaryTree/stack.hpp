#ifndef INC_3_1_STACK_STACK_HPP
#define INC_3_1_STACK_STACK_HPP

#include <exception>

struct StackOverflow : public std::exception
{
public:
  explicit StackOverflow(const char* text)
  {
    what_ = text;
  }

  const char* what() const noexcept override
  {
    return what_;
  }

private:
  const char* what_;
};

struct StackUnderflow : public std::exception
{
public:
  explicit StackUnderflow(const char* text)
  {
    what_ = text;
  }

  const char* what() const noexcept override
  {
    return what_;
  }

private:
  const char* what_;
};

struct WrongStackSize : public std::exception
{
public:
  explicit WrongStackSize(const char* text)
  {
    what_ = text;
  }

  const char* what() const noexcept override
  {
    return what_;
  }

private:
  const char* what_;
};

template<class T>
class Stack
{
public:

  virtual ~Stack() = default;

  virtual void push(const T &src) = 0;

  virtual T pop() = 0;

  virtual const T &peek() = 0;

  virtual bool isEmpty() = 0;

};

template<class T>
class StackArray: public Stack<T>
{
public:

  StackArray(int size)
  {
    if (size <= 0)
    {
      throw WrongStackSize("The size of the stack should be positive");
    }
    stack_ = new T[size];
    size_ = size;
    currElem_ = -1;
  }

  ~StackArray()
  {
    delete[] stack_;
    size_ = 0;
    currElem_ = 0;
  }

  void push(const T &src) override
  {
    if ((currElem_ + 1) == size_)
    {
      throw StackOverflow("The stack has exceeded it's predefined volume");
    }
    currElem_ += 1;
    stack_[currElem_] = src;
  }

  T pop() override
  {
    if (isEmpty())
    {
      throw StackUnderflow("This stack is empty already. There is nothing to pop from it");
    }
    T &temp = stack_[currElem_];
    currElem_ -= 1;
    return temp;
  }

  const T &peek() override
  {
    if (isEmpty())
    {
      throw StackUnderflow("This stack is empty.");
    }
    return stack_[currElem_];
  }

  bool isEmpty() override
  {
    return (currElem_ == -1);
  }

private:
  int size_;
  int currElem_;
  T *stack_;
};

#endif //INC_3_1_STACK_STACK_HPP
