#include <iostream>
#include <ctime>
#include <cmath>
#include <chrono>
#include "bubbleSort.hpp"
#include "pocketSort.hpp"
#include "pyramidSort.hpp"

using namespace std::chrono;
int size = 0;

template<class T>
void testSorting(const char *name, std::vector<T> array, void (*sortingAlgorithm)(T *array, long size));

int main()
{
  std::cout << "-----TESTINGS OF BEST CASE SCENARIOS-----\n";
  for(int i = 1; i < 4; i++)
  {
    size = 10 * std::pow(10, i);
    std::vector<long> array;
    array.reserve(size);
    for (int j = 0; j < size; j++)
    {
      array.push_back(i);
    }
    std::cout << "\n---- Testing array of ascending numbers of " << size << " elements ---- \n";
    testSorting("bubble sort", array, &bubbleSort);
    testSorting("pocket sort", array, &pocketSort);
    testSorting("pyramid sort", array, &pocketSort);
    std::cout << "\n-----Testing array of ascending numbers of " << size << " elements ended-----\n";
  }
  std::cout << "\n-----BEST TEST SCENARIOS ENDED SUCCESSFULLY-----\n";



  std::cout << "-----TESTINGS OF AVERAGE CASE SCENARIOS-----\n";
  for(int i = 1; i < 4; i++)
  {
    size = 10 * std::pow(10, i);
    srand(time(nullptr));
    std::vector<long> array;
    array.reserve(size);
    for (int j = 0; j < size; j++)
    {
      array.push_back(rand());
    }
    std::cout << "\n---- Testing array of random numbers of " << size << " elements ---- \n";
    testSorting("bubble sort", array, &bubbleSort);
    testSorting("pocket sort", array, &pocketSort);
    testSorting("pyramid sort", array, &pocketSort);
    std::cout << "\n-----Testing random array of " << size << " elements ended-----\n";
  }
  std::cout << "\n-----AVERAGE TEST SCENARIOS ENDED SUCCESSFULLY-----\n";

  std::cout << "-----TESTINGS OF WORST CASE SCENARIOS-----\n";
  for(int i = 1; i < 4; i++)
  {
    size = 10 * std::pow(10, i);
    std::vector<long> array;
    array.reserve(size);
    for (int j = size - 1; j >= 0; j--)
    {
      array.push_back(size);
    }
    std::cout << "\n---- Testing array of descending numbers of " << size << " elements ---- \n";
    testSorting("bubble sort", array, &bubbleSort);
    testSorting("pocket sort", array, &pocketSort);
    testSorting("pyramid sort", array, &pocketSort);
    std::cout << "\n-----Testing array of descending numbers of " << size << " elements ended-----\n";
  }
  std::cout << "\n-----WORST TEST SCENARIOS ENDED SUCCESSFULLY-----\n";
}

template<class T>
void testSorting(const char *name, std::vector<T> array, void (*sortingAlgorithm)(T *array, long size))
{
  std::vector<T> arrayForStandardSort = array;
  auto standardTime1 = high_resolution_clock::now();
  std::sort(arrayForStandardSort.begin(), arrayForStandardSort.end());
  auto standardTime2 = high_resolution_clock::now();
  auto standardDuration = duration_cast<microseconds>(standardTime2 - standardTime1);
  auto testingTime1 = high_resolution_clock::now();
  sortingAlgorithm(array.data(), array.size());
  auto testingTime2 = high_resolution_clock::now();
  auto testingDuration = duration_cast<microseconds>(testingTime2 - testingTime1);

  std::cout << "\n--- Testing " << name << " ---\n";

  for (typename std::vector<T>::size_type i = 0; i < array.size(); i++)
  {
    if (array.at(i) != arrayForStandardSort.at(i))
    {
      std::cout << "The sorting algorithm failed to do it's job correctly!\n";
      return;
    }
  }

  std::cout << "The sorting was done correctly!\n";
  std::cout << "Standard algorithm took " << standardDuration.count() << " microseconds\n";
  std::cout << name << " algorithm took " << testingDuration.count() << " microseconds\n";
  double difference = static_cast<double>(testingDuration.count()) / static_cast<double>(standardDuration.count());
  std::cout << "Standard duration is " << difference << " quicker than " << name << " algorithm\n";

  std::cout << "--- Test of " << name << " ended---\n";
}
