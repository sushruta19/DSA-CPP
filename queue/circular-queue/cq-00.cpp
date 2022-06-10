/*Implementation of Circular Queue(FIFO) by Array*/

#include<iostream>
using namespace std;

class CircularQueue
{
  public:
  int front, rear, capacity;
  int *a;

  CircularQueue(int cap)
  {
    front = rear = -1;
    capacity = cap;
    a = new int[capacity];
  }

  bool isEmpty()
  {
    return (front == -1);
  }

  bool isFull()
  {
    return (front == (rear+1)%capacity);
  }

  void enqueue(int value)
  {
    if(this->isFull())
      throw overflow_error("Queue Overflow!\n");
    else if(this->isEmpty())
      front = 0;
    rear = (rear+1)%capacity;
    a[rear] = value;
  }

  void dequeue()
  {
    if(this->isEmpty())
      throw underflow_error("Queue is already Empty!\n");
    else if(front == rear)      //Queue has only on element
    {
      front = rear = -1;        //Queue gets empty
    }
    else
    {
      front = (front+1)%capacity;
    }
  }

  int showFront()
  {
    if(this->isEmpty())
      throw underflow_error("Queue is Empty!\n");
    return a[front];
  }

  void display()
  {
    if(front <= rear)
    {
      for(int i=front;i<=rear;i++)
        cout<<a[i]<<" ";
    }
    else
    {
      for(int i=front; i<capacity;i++)
        cout<<a[i]<<" ";
      for(int j=0;j<=rear;j++)
        cout<<a[j]<<" ";
    }
    cout<<endl;
  }

  ~CircularQueue()
  {
    delete[] a;
  }
};

//Driver Program
int main()
{
	CircularQueue q(5);
	for(int i=1; i<=5; i++)
    q.enqueue(i);

  cout<<"Queue is ";
	q.display();
	cout<<"Front element is "<< q.showFront()<<endl;
	
	q.dequeue();
	q.enqueue(6);
	q.dequeue();
	q.enqueue(7);
	cout<<"Queue is ";
  q.display();
}		