#include "Vocabulary.hpp"
#include <string>
#include <algorithm>
#include <memory>

std::istream &operator>>(std::istream &in, Vocabulary &src)
{
  while (!in.eof())
  {
    std::string temp, line;
    in >> temp;
    for (unsigned int i = 0; i < temp.size(); ++i) {
      if ((temp[i] >= 'a' && temp[i] <= 'z') || (temp[i] >= 'A' && temp[i] <= 'Z')) {
        line = line + temp[i];
      }
    }
    temp = line;
    for (char &i : temp)
    {
      i = std::tolower(i);
    }
    if (temp.empty())
    {
      continue;
    }
    for(auto i = temp.begin(); i != std::prev(temp.end()); i++)
    {
      src.updateStats(*i, *std::next(i));
    }
  }
  return in;
}

void Vocabulary::updateStats(char letter, char letterAfter)
{
  vocabulary[letter].amount += 1;
  vocabulary[letter].nextLetterFrequency[letterAfter] += 1;
}

std::string Vocabulary::buildWord(unsigned int length)
{
  if(length == 0)
  {
    return "";
  }
  std::string word;
  unsigned int size = vocabulary.size();
  int letterNum = (rand() / double(RAND_MAX)) * size;
  auto iter = vocabulary.begin();
  for(int i = 0; i < letterNum; i++)
  {
    iter++;
  }
  word.push_back(iter->first);
  for(unsigned int i = 1; i <= length; i++)
  {
    unsigned long long random = (rand() / double(RAND_MAX)) * iter->second.amount;
    unsigned long long sum = 0;
    auto newIter = iter->second.nextLetterFrequency.begin();
    for(auto j = iter->second.nextLetterFrequency.begin(); j != iter->second.nextLetterFrequency.end(); j++)
    {
      sum += j->second;
      if(sum >= random)
      {
        newIter = j;
        break;
      }
    }
    word.push_back(newIter->first);
    iter = vocabulary.find(newIter->first);
  }

  return word;
}
