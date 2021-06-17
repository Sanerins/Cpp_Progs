#ifndef INC_9_1_DUMBAI_VOCABULARY_HPP
#define INC_9_1_DUMBAI_VOCABULARY_HPP
#include <map>
#include <iostream>
#include <string>

struct letterInfo
{
  std::map<char, unsigned long> nextLetterFrequency;
  unsigned long long amount = 0;
};

class Vocabulary
{
public:
  friend std::istream &operator>>(std::istream &in, Vocabulary &src);

  std::string buildWord(unsigned int length);
private:
  std::map<char, letterInfo> vocabulary;

  void updateStats(char letter, char letterAfter);
};

#endif //INC_9_1_DUMBAI_VOCABULARY_HPP
