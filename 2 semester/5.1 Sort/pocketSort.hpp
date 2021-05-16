#ifndef INC_5_1_SORT_POCKETSORT_HPP
#define INC_5_1_SORT_POCKETSORT_HPP

#include <algorithm>
#include <vector>

template<class T>
void pocketSort(T* array, long size)
{
  const int n = 10;
  std::vector<T> buckets[n];

  T max = array[0];
  T min = array[0];

  for(long i = 1; i < size; i++)
  {
    max = std::max(array[i], max);
    min = std::min(array[i], min);
  }

  for(long i = 0; i < size; i++)
  {
    int bi = n * ((array[i] - min) / ((max - min + 0.01) * 1.0));
    buckets[bi].push_back(array[i]);
  }

  for(int i = 0; i < n; i++)
  {
    std::sort(buckets[i].begin(), buckets[i].end());
  }

  int currIndex = 0;
  for(int i = 0; i < size; i++)
  {
    while (!buckets[currIndex].empty())
    {
      array[i] = buckets[currIndex][0];
      buckets[currIndex].erase(buckets[currIndex].begin());
      i++;
    }
    i--;
    currIndex++;
  }
}

#endif //INC_5_1_SORT_POCKETSORT_HPP
