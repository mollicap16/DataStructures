#include <iostream>
#include <Stack.h>
#include <StackLL.h>

int main(){
  // STACK ARRAY IMPLEMENTATION TEST
  std::cout << "STACK ARRAY IMPLEMENTATION TEST" << std::endl;
  Stack stack(5);
  std::cout << "Is empty =  " << stack.IsEmpty() << std::endl;
  std::cout << stack.Pop() << std::endl << std::endl;

  stack.Push(5);
  std::cout << stack.Peek() << std::endl;
  stack.Push(-130);
  std::cout << stack.Peek() << std::endl;
  stack.Push(33);
  std::cout << stack.Peek() << std::endl;
  stack.PrintStack();
  stack.Pop();
  std::cout << stack.Peek() << std::endl;
  stack.Push(150);
  std::cout << stack.Peek() << std::endl;
  stack.Push(300);
  std::cout << stack.Peek() << std::endl;
  stack.Push(2750);
  std::cout << stack.Peek() << std::endl;
  stack.Push(5);
  std::cout << stack.Peek() << std::endl;
  stack.PrintStack();

  std::cout << stack.Pop() << std::endl;
  std::cout << stack.Peek() << std::endl;
  std::cout << stack.Pop() << std::endl;
  std::cout << stack.Peek() << std::endl;
  std::cout << stack.Pop() << std::endl;
  std::cout << stack.Peek() << std::endl;
  std::cout << stack.Pop() << std::endl;
  std::cout << stack.Peek() << std::endl;
  std::cout << stack.Pop() << std::endl;
  std::cout << stack.Peek() << std::endl;
  stack.PrintStack();
  std::cout << std::endl;

  // STACK LINKED LIST IMPLEMENTATION TEST
  std::cout << "STACKED LINKED LIST IMPLEMENTATION TEST \n";
  StackLL stackll;
  std::cout << "Is empty =  " << stackll.IsEmpty() << std::endl;
  std::cout << stackll.Pop() << std::endl << std::endl;

  stackll.Push(10);
  stackll.PrintStack();
  stackll.Pop();
  stackll.Pop();
  stackll.PrintStack();
  stackll.Push(100);
  std::cout << stackll.Peek() << std::endl;
  stackll.Push(200);
  std::cout << stackll.Peek() << std::endl;
  stackll.Push(-3000);
  std::cout << stackll.Peek() << std::endl;
  stackll.Push(400);
  std::cout << stackll.Peek() << std::endl;
  stackll.PrintStack();

  stackll.Pop();
  stackll.PrintStack();
  stackll.Pop();
  stackll.PrintStack();
  stackll.Pop();
  stackll.PrintStack();
  stackll.Pop();
  stackll.PrintStack();
  stackll.Pop();
  stackll.PrintStack();

  return 0;
}
