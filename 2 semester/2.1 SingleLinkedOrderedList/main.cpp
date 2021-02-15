#include <iostream>
#include "SinglyLinkedOrderedList.hpp"

int main()
{
  SinglyLinkedOrderedList List;
  List.Insert(6);
  List.Insert(6); //Checking that each value can be added only once
  List.Insert(3);
  List.Insert(9);
  List.Insert(5);
  List.Insert(4);
  std::cout << List << std::endl;
  std::cout << (List.Search(6)? "6 is found" : "6 is not found") << std::endl;
  std::cout << (List.Search(10)? "10 is found" : "10 is not found") << std::endl;
  List.Delete(6); //6 is now deleted
  std::cout << List << std::endl;
  List.Insert(6);
  std::cout << List << std::endl;

  SinglyLinkedOrderedList List1;
  List1.Insert(8);
  List1.Insert(3);
  List1.Insert(0);
  List1.Insert(5);
  List1.Insert(12);
  std::cout << List1 << std::endl;

  std::cout << '\n';

  std::cout << "List: " << List << std::endl;
  std::cout << "List1: " << List1 << std::endl;
  List.Intersect(&List1);
  std::cout << "List after intersection: " << List << std::endl;
  std::cout << "List1 is now empty: " << List1 << std::endl;

  List.Insert(6);
  List.Insert(3);
  List.Insert(9);
  List.Insert(5);
  List.Insert(4);
  List1.Insert(8);
  List1.Insert(3);
  List1.Insert(0);
  List1.Insert(5);
  List1.Insert(12);

  std::cout << '\n';

  std::cout << "List: " << List << std::endl;
  std::cout << "List1: " << List1 << std::endl;
  List.Combine(&List1);
  std::cout << "List after combining: " << List << std::endl;
  std::cout << "List1 is now empty: " << List1 << std::endl;

  List1.Insert(8);
  List1.Insert(3);
  List1.Insert(0);
  List1.Insert(5);
  List1.Insert(12);

  std::cout << '\n';

  //Testing "Show" function as well
  std::cout << "List: ";
  List.Show();
  std::cout << "List1: ";
  List1.Show();
  List.Exclude(&List1);
  std::cout << "List after excluding: ";
  List.Show();
  std::cout << "List1 is now empty: ";
  List1.Show();

  return 0;
}
