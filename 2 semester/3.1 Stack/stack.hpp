#ifndef INC_3_1_STACK_STACK_HPP
#define INC_3_1_STACK_STACK_HPP

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

#endif //INC_3_1_STACK_STACK_HPP
