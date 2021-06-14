#ifndef STACK_STACKARRAY_HPP
#define STACK_STACKARRAY_HPP

#include <memory>
#include "Stack.hpp"
#include "WrongStackSize.hpp"
#include "StackOverflow.hpp"
#include "StackUnderflow.hpp"

template<class T>
class StackArray: public Stack<T> {
public:
  explicit StackArray(int size = 100);
  StackArray(const StackArray<T> &src) = delete;
  StackArray(StackArray<T> &&src) noexcept;
  StackArray &operator=(const StackArray<T> &src) = delete;
  StackArray &operator=(StackArray<T> &&src) noexcept;

  void push(const T &e);
  T pop();
  bool isEmpty();

private:
  std::unique_ptr<T[]> array_;
  unsigned int top_{};
  unsigned int size_{};

  void swap(StackArray<T> &src);
};

template<class T>
StackArray<T>::StackArray(int size):
  top_(0),
  size_(size)
{
  if (size_ == 0)
  {
    throw  WrongStackSize();
  }
  array_ = std::unique_ptr<T []>(new T[size_]);
}

template<class T>
StackArray<T>::StackArray(StackArray<T> &&src) noexcept
{
  swap(src);
}

template<class T>
StackArray<T> &StackArray<T>::operator=(StackArray<T> &&src) noexcept
{
  if (this != &src)
  {
    swap( src);
  }
  return *this;
}

template<class T>
void StackArray<T>::push(const T &e)
{
  if (top_ != size_)
  {
    array_[top_] = e;
    ++top_;
  }
  else
  {
    throw StackOverflow();
  }
}

template<class T>
T StackArray<T>::pop()
{
  if (top_ != 0)
  {
    return array_[--top_];
  }
  else
  {
    throw StackUnderflow();
  }
}

template<class T>
bool StackArray<T>::isEmpty()
{
  return (top_ == 0);
}

template<class T>
void StackArray<T>::swap(StackArray<T> &src)
{
  std::swap(src.array_, array_);
  std::swap(src.top_, top_);
  std::swap(src.size_, size_);
}

#endif //STACK_STACKARRAY_HPP
