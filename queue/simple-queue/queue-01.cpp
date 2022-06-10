/*Implementation of Simple Queue(FIFO) by Array*/

/*******incomplete*********/

#include<iostream>
using namespace std;

class Queue
{
  public:
  int front, rear, capacity;
  int *a;

  Queue(int cap)
  {
    front = rear = -1;
    capacity = cap;
    a = new int[capacity];
  }

  bool isEmpty()
  {
    return (rear == -1 && front == -1);
  }
  
  void enqueue(int value)

};