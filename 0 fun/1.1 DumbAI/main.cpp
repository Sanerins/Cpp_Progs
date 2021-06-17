#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include "Vocabulary.hpp"

int main()
{
  std::cout << "Привет, зови меня \"Ебамозг\"\n";
  std::cout << "Я - искусственный интеллект, что будет пробовать генерировать слова, похожие на настоящие!\n";
  std::cout << "Обучи меня, и я стану сильнее!";
  srand(time(nullptr));
  Vocabulary vocabulary;
  std::ifstream file("WarAndPeace.txt");
  if(file.is_open())
  {
    file >> vocabulary;
  }

  for(int i = 0; i < 1000000; i++)
  {
    std::cout << vocabulary.buildWord((rand() / double(RAND_MAX)) * 15 + 1) << '\n';
  }
  return 0;
}
