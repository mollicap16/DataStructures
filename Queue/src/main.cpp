#include <iostream>
#include <Queue.h>
#include <QueueLL.h>
#include <QueueStack.h>

int main(){
  std::cout << "===================================================";
  std::cout << " QUEUE ARRAY IMPLEMENTATION ";
  std::cout << "===================================================" << std::endl;
  Queue queue(4);

  // Test 1
  std::cout << "============================= TEST 1 ================================" << std::endl;
  std::cout << queue.Dequeue() << std::endl;
  std::cout << queue.Dequeue() << std::endl;
  queue.PrintQueue();
  std::cout << queue.PeekRear() << std::endl;

  // Test 2
  std::cout << std::endl << std::endl;
  std::cout << "============================= TEST 2 ================================" << std::endl;
  queue.Enqueue(-10);
  queue.Enqueue(30);
  std::cout << queue.Dequeue() << std::endl;
  std::cout << queue.Dequeue() << std::endl;
  std::cout << queue.Dequeue() << std::endl;

  // Test 3
  std::cout << std::endl << std::endl;
  std::cout << "============================= TEST 3 ================================" << std::endl;
  queue.Enqueue(1);
  queue.Enqueue(2);
  queue.Enqueue(3);
  std::cout << "Enqueued 4 = " << queue.Enqueue(4) << std::endl;
  std::cout << "Enqueued 5 = " << queue.Enqueue(5) << std::endl;
  std::cout << "Enqueued 6 = " << queue.Enqueue(6) << std::endl;
  queue.PrintQueue();


  // Test 4
  std::cout << std::endl << std::endl;
  std::cout << "============================= TEST 4 ================================" << std::endl;
  queue.PrintQueue();
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  std::cout << queue.Dequeue() << std::endl;
  std::cout << queue.Dequeue() << std::endl;
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  std::cout << queue.Dequeue() << std::endl;
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  std::cout << queue.Dequeue() << std::endl;
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  std::cout << queue.Dequeue() << std::endl;
  queue.PrintQueue();

  // Test 5
  std::cout << std::endl << std::endl;
  std::cout << "============================= TEST 5 ================================" << std::endl;
  queue.Enqueue(5);
  queue.Enqueue(6);
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  queue.PrintQueue();
  queue.Dequeue();
  queue.Dequeue();
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  queue.Enqueue(100);
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  queue.Enqueue(200);
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  queue.Enqueue(300);
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  queue.Enqueue(400);
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  queue.PrintQueue();
  queue.Dequeue();
  queue.Enqueue(10000);
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  queue.PrintQueue();
  queue.Dequeue();
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  queue.Dequeue();
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  queue.Dequeue();
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  queue.Dequeue();
  std::cout << "Front Queue = " << queue.PeekFront() << " Rear Queue = " << queue.PeekRear() << std::endl;
  std::cout << std::endl << std::endl;

  std::cout << "===================================================";
  std::cout << " QUEUE LINKED LIST IMPLEMENTATION ";
  std::cout << "===================================================" << std::endl;
  QueueLL queue2;

  // Test 1
  std::cout << "============================= TEST 1 ================================" << std::endl;
  std::cout << queue2.Dequeue() << std::endl;
  queue2.PrintQueue();
  queue2.Enqueue(1);
  std::cout << "Front Value = " << queue2.PeekFront() << " Rear Value = " << queue2.PeekRear() << std::endl;
  queue2.Enqueue(2);
  std::cout << "Front Value = " << queue2.PeekFront() << " Rear Value = " << queue2.PeekRear() << std::endl;
  queue2.Enqueue(3);
  std::cout << "Front Value = " << queue2.PeekFront() << " Rear Value = " << queue2.PeekRear() << std::endl;
  queue2.PrintQueue();

  // Test 2
  std::cout << "============================= TEST 2 ================================" << std::endl;
  std::cout << queue2.Dequeue() << std::endl;   //(1)
  std::cout << "Front Value = " << queue2.PeekFront() << " Rear Value = " << queue2.PeekRear() << std::endl;
  std::cout << queue2.Dequeue() << std::endl;   //(2)
  std::cout << "Front Value = " << queue2.PeekFront() << " Rear Value = " << queue2.PeekRear() << std::endl;
  std::cout << queue2.Dequeue() << std::endl;   //(3)
  std::cout << "Front Value = " << queue2.PeekFront() << " Rear Value = " << queue2.PeekRear() << std::endl;
  std::cout << queue2.Dequeue() << std::endl;   //(Empty)
  std::cout << "Front Value = " << queue2.PeekFront() << " Rear Value = " << queue2.PeekRear() << std::endl;

  // Test 3
  std::cout << "============================= TEST 3 ================================" << std::endl;
  queue2.Enqueue(1);
  std::cout << "Front Value = " << queue2.PeekFront() << " Rear Value = " << queue2.PeekRear() << std::endl;
  queue2.Enqueue(2);
  std::cout << "Front Value = " << queue2.PeekFront() << " Rear Value = " << queue2.PeekRear() << std::endl;
  queue2.Enqueue(3);
  std::cout << "Front Value = " << queue2.PeekFront() << " Rear Value = " << queue2.PeekRear() << std::endl;
  queue2.Enqueue(4);
  std::cout << "Front Value = " << queue2.PeekFront() << " Rear Value = " << queue2.PeekRear() << std::endl;
  queue2.PrintQueue();
  std::cout << queue2.Dequeue() << std::endl;
  queue2.PrintQueue();
  std::cout << queue2.Dequeue() << std::endl;
  queue2.PrintQueue();
  queue2.Enqueue(1);
  queue2.Enqueue(2);
  queue2.Enqueue(5);
  queue2.PrintQueue();
  queue2.Dequeue();
  queue2.Enqueue(1000);
  queue2.Enqueue(50);
  queue2.PrintQueue();
  std::cout << std::endl << std::endl;

  std::cout << "===================================================";
  std::cout << " QUEUE STACK IMPLEMENTATION ";
  std::cout << "===================================================" << std::endl;
  QueueStack queue3;

  // Test 1
  std::cout << "============================= TEST 1 ================================" << std::endl;
  queue3.Dequeue();
  std::cout << "Front Value = " << queue3.PeekFront() << " Rear Value = " << queue3.PeekRear() << std::endl;
  queue3.Dequeue();
  std::cout << "Front Value = " << queue3.PeekFront() << " Rear Value = " << queue3.PeekRear() << std::endl;
  queue3.PrintQueue();

  // Test 2
  std::cout << "============================= TEST 2 ================================" << std::endl;
  queue3.Enqueue(1);
  queue3.Enqueue(2);
  std::cout << "Front Value = " << queue3.PeekFront() << " Rear Value = " << queue3.PeekRear() << std::endl;
  queue3.PrintQueue();
  std::cout << queue3.Dequeue() << std::endl;
  queue3.PrintQueue();
  queue3.Enqueue(3);
  std::cout << "Front Value = " << queue3.PeekFront() << " Rear Value = " << queue3.PeekRear() << std::endl;
  queue3.PrintQueue();
  queue3.Enqueue(4);
  queue3.Enqueue(5);
  queue3.PrintQueue();
  std::cout << "Front Value = " << queue3.PeekFront() << " Rear Value = " << queue3.PeekRear() << std::endl;

  // Test 3
  std::cout << "============================= TEST 3 ================================" << std::endl;
  std::cout << queue3.Dequeue() << std::endl;
  std::cout << "Front Value = " << queue3.PeekFront() << " Rear Value = " << queue3.PeekRear() << std::endl;
  std::cout << queue3.Dequeue() << std::endl;
  std::cout << "Front Value = " << queue3.PeekFront() << " Rear Value = " << queue3.PeekRear() << std::endl;
  std::cout << queue3.Dequeue() << std::endl;
  std::cout << "Front Value = " << queue3.PeekFront() << " Rear Value = " << queue3.PeekRear() << std::endl;
  std::cout << queue3.Dequeue() << std::endl;
  std::cout << "Front Value = " << queue3.PeekFront() << " Rear Value = " << queue3.PeekRear() << std::endl;
  std::cout << queue3.Dequeue() << std::endl;
  std::cout << "Front Value = " << queue3.PeekFront() << " Rear Value = " << queue3.PeekRear() << std::endl;

  // Test 4
  std::cout << "============================= TEST 4 ================================" << std::endl;
  queue3.Enqueue(1);
  queue3.Enqueue(300);
  queue3.PrintQueue();
  queue3.Dequeue();
  queue3.PrintQueue();
  queue3.Enqueue(9000);
  queue3.Enqueue(-9000);
  queue3.PrintQueue();
  queue3.Dequeue();
  queue3.Dequeue();
  queue3.Enqueue(1);
  queue3.Enqueue(2);
  queue3.Enqueue(3);
  queue3.Enqueue(1);
  queue3.Enqueue(1);
  queue3.Enqueue(1);
  queue3.Enqueue(1000);
  queue3.PrintQueue();
  queue3.Dequeue();
  queue3.Dequeue();
  queue3.Dequeue();
  queue3.Dequeue();
  queue3.Dequeue();
  queue3.Dequeue();
  queue3.Dequeue();
  queue3.PrintQueue();

  return 0;
}
