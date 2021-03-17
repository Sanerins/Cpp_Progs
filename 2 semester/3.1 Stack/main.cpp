#include <iostream>
#include <memory>
#include <cstring>
#include <exception>
#include "stack.hpp"
#include "listStack.hpp"
#include "arrayStack.hpp"

const std::string num = "0123456789";
const std::string openingBr = "({[";
const std::string closingBr = ")}]";
const std::string sig2 = "+-*/";

bool CheckBalanceBrackets(std::string &src, int size = 0);

bool getPostfixFromInfix(std::string &src, std::string &postfix, int size = 0);

int evaluatePostfix(std::string src, int size = 0);

int main()
{
  {
    StackArray<int> test(3);
    std::cout << test.isEmpty() << '\n';
    test.push(5);
    test.push(4);
    std::cout << test.pop() << '\n';

    test.push(3);
    test.push(2);
    std::cout << test.pop() << test.pop() << test.pop() << '\n';
    test.push(5);
    test.push(4);
  }

  std::cout << "\n";

  {
    StackList<int> test(3);
    test.pop();

    std::cout << test.isEmpty() << '\n';

    test.push(5);
    test.push(4);
    std::cout << test.pop() << '\n';

    test.push(3);
    test.push(2);
    std::cout << test.pop() << test.pop() << test.pop() << '\n';
    test.push(5);
    test.push(4);
  }

  std::string brackets1 = "{  { }  (  [ ] ) }";
  std::string brackets2 = "[[]}";
  std::string brackets3 = "[{])";

  std::cout << "\n Checking brackets using stack as a list: \n" << "{  { }  (  [ ] ) } : " << CheckBalanceBrackets(brackets1)
            << "\n" << "[[]} : " << CheckBalanceBrackets(brackets2) << "\n" << "[{]) : " << CheckBalanceBrackets(brackets3) << "\n";

  brackets1 = "{  { }  (  [ ] ) }";
  brackets2 = "[[]}";
  brackets3 = "[{])";

  std::cout << "\n Checking brackets using stack as an array: \n" << "{  { }  (  [ ] ) } : "
            << CheckBalanceBrackets(brackets1, 30) << "\n" << "[[]} : " << CheckBalanceBrackets(brackets2, 10) << "\n" << "[{]) : "
            << CheckBalanceBrackets(brackets3, 10) << "\n";

  int answer = (((3890 - 453) / 23) + ((525 - (120 * 4)) * 210)) - ((340 * 10) - 200);
  std::string postfix;
  std::string src = "{[(3890 - 453) / 23] + [{525 - (120 * 4)} * 210]} - [(340 * 10) - 200]";
  std::cout << "\n Getting postfix from infix and solving it using list: \n" << src << " --> ";
  getPostfixFromInfix(src, postfix);
  std::cout << postfix << " = " << evaluatePostfix(postfix) << "\n" << " The real answer: " << answer << "\n";

  postfix = "";
  std::string src1 = "{[(3890 - 453) / 23] + [{525 - (120 * 4)} * 210]} - [(340 * 10) - 200]";
  std::cout << "\n Getting postfix from infix and solving it using array: \n" << src1 << " --> ";
  getPostfixFromInfix(src1, postfix, 30);
  std::cout << postfix << " = " << evaluatePostfix(postfix, 30) << "\n" << " The real answer: " << answer << "\n";
  return 0;
}

bool CheckBalanceBrackets(std::string &src, int size)
{
  std::unique_ptr<Stack<char>> stack;
  if (size <= 0)
  {
    stack = std::make_unique<StackList<char>>(0);
    stack->pop();
  }
  else
  {
    stack = std::make_unique<StackArray<char>>(size);
  }

  if (src[0] == '\0')
  {
    return false;
  }

  while (src[0] != '\0')
  {
    if (src[0] == ' ')
    {
    }
    else if (src[0] == '{' or src[0] == '[' or src[0] == '(')
    {
      stack->push(src[0]);
    }
    else if (stack->isEmpty())
    {
      return false;
    }
    else if (src[0] == '}')
    {
      if (stack->pop() != '{')
      {
        return false;
      }
    }
    else if (src[0] == ']')
    {
      if (stack->pop() != '[')
      {
        return false;
      }
    }
    else if (src[0] == ')')
    {
      if (stack->pop() != '(')
      {
        return false;
      }
    }
    else
    {
      return false;
    }
    src.erase(0, 1);
  }

  if (!stack->isEmpty())
  {
    return false;
  }
  return true;
}

bool getPostfixFromInfix(std::string &src, std::string &postfix, int size)
{
  std::unique_ptr<Stack<char>> stack;
  if (size <= 0)
  {
    stack = std::make_unique<StackList<char>>(0);
    stack->pop();
  }
  else
  {
    stack = std::make_unique<StackArray<char>>(size);
  }

  if (src[0] == '\0')
  {
    return false;
  }

  while (src[0] != '\0')
  {
    if (src[0] == ' ')
    {
      src.erase(0, 1);
    }
    else if (num.find(src[0]) != std::string::npos)
    {
      while (num.find(src[0]) != std::string::npos)
      {
        postfix += src[0];
        src.erase(0, 1);
      }
      postfix += ' ';
    }
    else
    {
      if (stack->isEmpty() or openingBr.find(src[0]) != std::string::npos)
      {
        stack->push(src[0]);
      }
      else if (closingBr.find(src[0]) != std::string::npos)
      {
        int bracket = closingBr.find(src[0]);
        while (stack->peek() != openingBr[bracket])
        {
          postfix += stack->pop();
          postfix += ' ';
        }
        stack->pop();
      }
      else if (src[0] == '+' or src[0] == '-')
      {
        while (!stack->isEmpty() and (sig2.find(stack->peek()) != std::string::npos))
        {
          postfix += stack->pop();
          postfix += ' ';
        }
        stack->push(src[0]);
      }
      else if (src[0] == '*' or src[0] == '/')
      {
        while (stack->peek() == '*' or stack->peek() == '/')
        {
          postfix += stack->pop();
          postfix += ' ';
        }
        stack->push(src[0]);
      }
      else
      {
        throw std::invalid_argument("The equation is improper");
      }
      src.erase(0, 1);
    }
  }

  while (!stack->isEmpty())
  {
    postfix += stack->pop();
    postfix += ' ';
  }
  postfix.erase(postfix.length(), 1);
  return true;
}

int evaluatePostfix(std::string src, int size)
{
  std::unique_ptr<Stack<int>> stack;
  if (size <= 0)
  {
    stack = std::make_unique<StackList<int>>(0);
    stack->pop();
  }
  else
  {
    stack = std::make_unique<StackArray<int>>(size);
  }

  if (src.empty())
  {
    return 0;
  }

  int sum = 0;

  while (!src.empty())
  {
    if (src[0] == ' ')
    {
      src.erase(0, 1);
    }
    else if (num.find(src[0]) != std::string::npos)
    {
      int temp = 0;
      while (num.find(src[0]) != std::string::npos)
      {
        temp = temp * 10 + (src[0] - '0');
        src.erase(0, 1);
      }
      stack->push(temp);
    }
    else if (src[0] == '+')
    {
      int b = stack->pop();
      int a = stack->pop();
      stack->push(a + b);
      src.erase(0, 1);
    }
    else if (src[0] == '*')
    {
      int b = stack->pop();
      int a = stack->pop();
      stack->push(a * b);
      src.erase(0, 1);
    }
    else if (src[0] == '-')
    {
      int b = stack->pop();
      int a = stack->pop();
      stack->push(a - b);
      src.erase(0, 1);
    }
    else if (src[0] == '/')
    {
      int b = stack->pop();
      int a = stack->pop();
      stack->push(a / b);
      src.erase(0, 1);
    }
    else
    {
      throw std::invalid_argument("Evaluation can not be made");
    }
  }
  sum = stack->pop();
  if (!stack->isEmpty())
  {
    throw std::invalid_argument("Evaluation can not be made");
  }
  return sum;
}
