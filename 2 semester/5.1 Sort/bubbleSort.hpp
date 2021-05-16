#ifndef INC_5_1_SORT_BUBBLESORT_HPP
#define INC_5_1_SORT_BUBBLESORT_HPP

template<class T>
void bubbleSort(T* array, long size)
{
  for(long i = 0; i < size; i++)
  {
    for(long j = 0; j < size - 1 - i; j++)
    {
      if(array[j] > array[j + 1])
      {
        T temp = array[j + 1];
        array[j + 1] = array[j];
        array[j] = temp;
      }
    }
  }
}

#endif //INC_5_1_SORT_BUBBLESORT_HPP
