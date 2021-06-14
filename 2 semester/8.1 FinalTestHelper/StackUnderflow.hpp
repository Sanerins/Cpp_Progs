#ifndef STACK_STACKUNDERFLOW_HPP
#define STACK_STACKUNDERFLOW_HPP

#include <exception>

class StackUnderflow : public std::exception {
public:
  const char * what() const noexcept override;
};

const char *StackUnderflow::what() const noexcept
{
  return "StackUnderflow\n";
}

#endif //STACK_STACKUNDERFLOW_HPP
