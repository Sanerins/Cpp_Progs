#ifndef INC_4_1_BINARYTREE_FREQUENCYBOOK_HPP
#define INC_4_1_BINARYTREE_FREQUENCYBOOK_HPP

#include <iostream>
#include <map>
#include <string>
#include "BinarySearchTree.hpp"


class FrequencyBook
{
public:

  friend std::istream &operator>>(std::istream &in, FrequencyBook &book);

  std::multimap<int, std::string> getFrequency();

  void showFrequency(int counter = 0);

  bool insert(std::string& word);

  bool search(std::string& word);

  bool deleteWord(std::string& word);

private:
  BinarySearchTree words;
};

#endif //INC_4_1_BINARYTREE_FREQUENCYBOOK_HPP
