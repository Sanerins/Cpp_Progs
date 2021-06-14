#include <iostream>
#include "BinarySearchTree.hpp"

//Дерево для построения
const std::vector<int> tree = {5, 8, 4, 7, 2, 3, 1, 9};
const std::string evaluation = "(a/b-c)*(d-e*f)+g";

void printKey(int x)
{
  std::cout << x << ' ';
}

bool getPostfixFromInfix(const std::string &infix, std::string &postfix, size_t stackSize = 50);

int main()
{
  BinarySearchTree<int> a;
  // сюда вставить инфу в таком же порядке
  std::vector<int> v = tree;
  a.insert(v);
  std::cout << "Tree\n";
  a.print(std::cout);
  std::cout << "\nИнфиксный обход\n";
  a.iterativeInorderWalk(printKey);
  std::cout << "\nобход сверху вниз\n";
  a.inorderWalk(printKey);
  std::cout << "\nобход снизу вверх\n";
  a.inorderWalkFromDown(printKey);
  std::cout << "\nобход по уровням\n";
  a.bfs(printKey);
  std::cout << "\nмаксимальное число сравнений или высота\n";
  std::cout << a.getHeight();

  std::cout << "\n\nPostfix для выражений\n";
  //сюда вставить инфу
  std::string infix = evaluation;
  std::string postfix;
  std::cout << "из этого получаем " << infix << '\n';
  getPostfixFromInfix(infix, postfix);
  std::cout << postfix << '\n';
}

bool getPostfixFromInfix(const std::string &infix, std::string &postfix, size_t stackSize)
{
  StackArray<char> stack(stackSize);
  for (char temp : infix)
  {
    if (temp == ' ') continue;
    if (temp == '(')
    {
      stack.push(temp);
    }
    else if (temp == ')')
    {
      if (!stack.isEmpty())
      {
        char c = stack.pop();
        while (c != '(')
        {
          postfix += c;
          if (!stack.isEmpty())
          {
            c = stack.pop();
          }
          else
          {
            break;
          }
        }
      }
    }
    else if (temp == '+' or temp == '-')
    {
      if (!stack.isEmpty())
      {
        char c = stack.pop();
        if (c == '(')
        {
          stack.push(c);
        }
        while (c != '(' and (c == '*' or c == '/' or c == '-' or c == '+'))
        {
          postfix += c;
          if (!stack.isEmpty())
          {
            c = stack.pop();
          }
          else
          {
            break;
          }
        }
      }
      stack.push(temp);
    }
    else if (temp == '*' or temp == '/')
    {
      if (!stack.isEmpty())
      {
        char c = stack.pop();
        if (c == '+' or c == '-')
        {
          stack.push(c);
        }
        while (c != '(' and (c == '*' or c == '/'))
        {
          postfix += c;
          if (!stack.isEmpty())
          {
            c = stack.pop();
            if (c == '+' or c == '-')
            {
              stack.push(c);
            }
          }
          else
          {
            return false;
          }
        }
      }
      stack.push(temp);
    }
    else
    {
      postfix += temp;
    }
  }
  char c;
  while (!stack.isEmpty())
  {
    c = stack.pop();
    if (c != '+' and c != '/' and c != '*' and c != '-')
    {
      return false;
    }
    postfix += c;
  }
  return true;
}
