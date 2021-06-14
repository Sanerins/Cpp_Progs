#include <iostream>
#include <fstream>
#include <map>
#include "FrequencyBook.hpp"

int main()
{
  FrequencyBook book;
  std::ifstream file("test.txt");
  if(file.is_open())
  {
    file >> book;
    file.close();
  }
  //если подставить аргумент n, то будет n слов
  //например для трех самых популярных - book.showFrequency(3);
  //в данный момент настроено на вывод всех слов
  book.showFrequency(3);
  return 0;
}
