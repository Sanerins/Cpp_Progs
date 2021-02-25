#include <iostream>
#include "SinglyLinkedOrderedList.hpp"

int main()
{
  SinglyLinkedOrderedList list;
  list.Insert(6);
  list.Insert(6); //Checking that each value can be added only once
  list.Insert(3);
  list.Insert(9);
  list.Insert(5);
  list.Insert(4);
  std::cout << list << std::endl;
  std::cout << (list.Search(6) ? "6 is found" : "6 is not found") << std::endl;
  std::cout << (list.Search(10) ? "10 is found" : "10 is not found") << std::endl;
  list.Delete(6); //6 is now deleted
  std::cout << list << std::endl;
  list.Insert(6);
  std::cout << list << std::endl;

  SinglyLinkedOrderedList list1;
  list1.Insert(8);
  list1.Insert(3);
  list1.Insert(0);
  list1.Insert(5);
  list1.Insert(12);
  std::cout << list1 << std::endl;

  list.Insert(39);
  list.Insert(13);
  list.Insert(28);
  list.Insert(34);
  list.Insert(93);
  list.Insert(77);
  list1.Insert(13);
  list1.Insert(67);
  list1.Insert(54);
  list1.Insert(28);
  list1.Insert(92);
  list1.Insert(93);

  std::cout << '\n';

  std::cout << "list: " << list << std::endl;
  std::cout << "list1: " << list1 << std::endl;
  list.Intersect(&list1);
  std::cout << "list after intersection: " << list << std::endl;
  std::cout << "list1 is now empty: " << list1 << std::endl;

  list.Insert(6);
  list.Insert(3);
  list.Insert(9);
  list.Insert(5);
  list.Insert(4);
  list1.Insert(8);
  list1.Insert(3);
  list1.Insert(0);
  list1.Insert(5);
  list1.Insert(12);
  list.Insert(39);
  list.Insert(13);
  list.Insert(28);
  list.Insert(34);
  list.Insert(93);
  list.Insert(77);
  list1.Insert(13);
  list1.Insert(67);
  list1.Insert(54);
  list1.Insert(28);
  list1.Insert(92);
  list1.Insert(93);

  std::cout << '\n';

  std::cout << "list: " << list << std::endl;
  std::cout << "list1: " << list1 << std::endl;
  list.Combine(&list1);
  std::cout << "list after combining: " << list << std::endl;
  std::cout << "list1 is now empty: " << list1 << std::endl;

  list1.Insert(8);
  list1.Insert(3);
  list1.Insert(0);
  list1.Insert(5);
  list1.Insert(12);
  list1.Insert(13);
  list1.Insert(67);
  list1.Insert(54);
  list1.Insert(28);
  list1.Insert(92);
  list1.Insert(93);

  std::cout << '\n';

  //Testing "Show" function as well
  std::cout << "list: ";
  list.Show();
  std::cout << "list1: ";
  list1.Show();
  list.Exclude(&list1);
  std::cout << "list after excluding: ";
  list.Show();
  std::cout << "list1 is now empty: ";
  list1.Show();

  std::cout << '\n';

  list1 = std::move(list);
  std::cout << "list1 after moving: " << list1 << std::endl;
  std::cout << "list is now empty: " << list << std::endl;

  std::cout << '\n';

  list = list1;
  std::cout << "list after coping: " << list << std::endl;
  std::cout << "list1 is the same: " << list1 << std::endl;
  return 0;
}
