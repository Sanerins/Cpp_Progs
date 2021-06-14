#ifndef STACK_STACKOVERFLOW_HPP
#define STACK_STACKOVERFLOW_HPP
#include <exception>

class StackOverflow : public std::exception {
public:
  const char * what() const noexcept override;

};

const char *StackOverflow::what() const noexcept
{
  return "StackOverflow\n";
}

#endif //STACK_STACKOVERFLOW_HPP
