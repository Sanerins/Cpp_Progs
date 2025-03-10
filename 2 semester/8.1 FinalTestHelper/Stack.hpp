#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

template <class T>
class Stack
{
public:
  virtual ~Stack() = default;
  virtual void push(const T& e) = 0;
  virtual T pop() = 0;
  virtual bool isEmpty() = 0;
};
#endif //STACK_STACK_HPP
