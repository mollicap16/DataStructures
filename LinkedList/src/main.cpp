#include <iostream>
#include <Linkedlist.h>

int main(){
  std::cout << "Hello Linked List World" << std::endl;
  LinkedList list;

  list.AddNode(5);
  list.PrintList();
  list.DeleteTail();
  list.PrintList();
  std::cout << "List size = " << list.GetSize() << std::endl;

  list.AddNode(5);
  list.AddNode(10);
  list.AddNode(-1);
  list.AddNode(-20);
  list.AddNode(1000);
  list.PrintList();
  list.InsertAtStart(30);
  list.PrintList();
  list.InsertAtStart(42);
  list.PrintList();
  list.InsertAt(0,0);
  list.PrintList();
  list.InsertAt(1, 1);
  list.PrintList();
  list.InsertAt(3,3);
  list.PrintList();
  list.InsertAt(-10, -10); // Will not add anything to the list, can't have a negative index
  list.PrintList();
  list.InsertAt(11, 11); // Will not add anything to the list, can't add to a position larger than the size of the list
  list.PrintList();
  list.InsertAt(10, 10);
  list.PrintList();
  list.DeleteHead();
  list.PrintList();
  list.DeleteHead();
  list.PrintList();
  list.DeleteTail();
  list.PrintList();

  list.DeleteAt(2);
  list.PrintList();
  list.DeleteAt(0);
  list.PrintList();
  list.InsertAt(0,0);
  list.PrintList();
  std::cout << "Size of Linked list = " << list.GetSize() << std::endl;

  list.DeleteAt(6);
  list.PrintList();
  std::cout << "Size of Linked list = " << list.GetSize() << std::endl;
  list.InsertAt(5, 23);
  list.PrintList();

  bool ret = list.DeleteValue(-1000); // Should not delete anything and should return false.
  std::cout << "Delete value -1000 = " << ret << " size = " << list.GetSize() << std::endl;
  list.PrintList();

  ret = list.DeleteValue(0); // Deleting head based on the value, should return true.
  std::cout << "Delete value 0 = " << ret << " size = " << list.GetSize() << std::endl;
  list.PrintList();

  ret = list.DeleteValue(-20); // Deleting tail based on the value, should return true.
  std::cout << "Delete value -20 = " << ret << " size = " << list.GetSize() << std::endl;
  list.PrintList();

  ret = list.DeleteValue(10); // Deleting the middle node, should return true.
  std::cout << "Delete value 10 = " << ret << " size = " << list.GetSize() << std::endl;
  list.PrintList();

  return 0;
}
