#ifndef INC_3_1_STACK_EXCEPTIONS_HPP
#define INC_3_1_STACK_EXCEPTIONS_HPP

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

#endif //INC_3_1_STACK_EXCEPTIONS_HPP
