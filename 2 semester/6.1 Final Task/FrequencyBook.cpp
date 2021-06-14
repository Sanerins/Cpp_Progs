#include "FrequencyBook.hpp"
#include <string>
#include <exception>
const std::string symbols = "!?.,/\";:<>[]{}()|";

std::istream &operator>>(istream &in, FrequencyBook &book)
{
  std::string temp;
  while (!in.eof())
  {
    in >> temp;
    for(const char &i : symbols)
    {
      temp.erase(std::remove(temp.begin(), temp.end(), i), temp.end());
    }
    if(temp != "I")
    {
      for (char &i : temp)
      {
        i = std::tolower(i);
      }
    }
    if(temp.empty())
    {
      continue;
    }
    book.words.insert(temp);
    if(in.fail() && !in.eof())
    {
      throw std::invalid_argument("The input was bad");
    }
  }
  return in;
}

std::multimap<int, std::string> FrequencyBook::getFrequency()
{
  return words.getFrequency();
}

void FrequencyBook::showFrequency(int counter)
{
  std::multimap<int, std::string> frequency = getFrequency();
  if(counter <= 0)
  {
    for(auto i = frequency.rbegin(); i != frequency.rend(); i++)
    {
      std::cout << "Word: \"" << i->second << "\" can be found " << i->first << " times in this text" << "\n";
    }
  }
  else
  {
    auto iter = frequency.rbegin();
    for(int i = 0; i < counter; i++)
    {
      if(iter == frequency.rend())
      {
        break;
      }
      std::cout << "Word: \"" << iter->second << "\" can be found " << iter->first << " times in this text" << "\n";
      iter++;
    }
  }
}

bool FrequencyBook::insert(string &word)
{
  return words.insert(word);
}

bool FrequencyBook::search(string &word)
{
  return words.iterativeSearch(word);
}

bool FrequencyBook::deleteWord(string &word)
{
  return words.deleteItem(word);
}
