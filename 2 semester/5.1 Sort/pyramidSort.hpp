#ifndef INC_5_1_SORT_PYRAMIDSORT_HPP
#define INC_5_1_SORT_PYRAMIDSORT_HPP

template<class T>
void createHeap(T* array, long n, long i)
{
  long largest = i;
  long left = 2 * i + 1;
  long right = 2 * i + 2;
  if((left < n) && (array[largest] < array[left]))
  {
    largest = left;
  }

  if((right < n) && (array[largest] < array[right]))
  {
    largest = right;
  }

  if(largest != i)
  {
    std::swap(array[largest], array[i]);
    createHeap(array, n, largest);
  }
}

template<class T>
void pyramidSort(T* array, long n)
{
  for (long i = n / 2 - 1; i >= 0; i--)
  {
    createHeap(array, n, i);
  }

  for (int i = n - 1; i >= 0; i--) {
    std::swap(array[0], array[i]);
    createHeap(array, i, 0);
  }

}

#endif //INC_5_1_SORT_PYRAMIDSORT_HPP
