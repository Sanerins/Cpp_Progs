#include <iostream>
#include <ctime>
#include <chrono>
#include <list>
#include <iomanip>
#include "queue.hpp"
#include "stack.hpp"
#include "BinarySearchTree.hpp"

using namespace std::chrono;

int main()
{
  BinarySearchTree<double> tree;
  for(int i = 0; i < 125; i++)
  {
    srand(time(nullptr));
    std::list<double> list;
    for(int j = 0; j < 1000000; j++)
    {
      list.push_back(rand());
    }
    auto standardTime1 = high_resolution_clock::now();
    for(double & j : list)
    {
      tree.insert(j);
    }
    auto standardTime2 = high_resolution_clock::now();
    auto standardDuration = duration_cast<nanoseconds>(standardTime2 - standardTime1);
    std::cout << static_cast<double>(standardDuration.count()) / 1000000 << "\n";
  }
}
