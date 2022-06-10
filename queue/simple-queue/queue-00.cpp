/*Implementation of Simple Queue(FIFO) by Singly Linked List*/

#include<iostream>
#include<stdexcept>
using namespace std;

class Node
{
  public:
  int data;
  Node* next;
  Node(int x=0):data{x},next{NULL}{}
};

class Queue
{
  public:
  Node* front, *rear;

  Queue():front{NULL},rear{NULL}{}

  bool isEmpty()
  {
    return (front == NULL);
  }

  void enqueue(int value)
  {
    Node* new_node = new Node(value);
    if(this->isEmpty())
    {
      front = new_node;
      rear = new_node;
    }
    else
    {
      rear->next = new_node;
      rear = new_node;
    }
  }

  void dequeue()
  {
    if(this->isEmpty())
      throw underflow_error("Queue is Empty!\n");
    Node* temp = front;       //FIFO
    front = front->next;
    delete temp;

    if(front == NULL)  //if the queue becomes empty, rear has to be set NULL
      rear = NULL;
  }

  int showFront()
  {
    if(this->isEmpty())
      throw underflow_error("Queue is Empty!\n");
    return front->data;
  }

  void display()
  {
    if(this->isEmpty())
    {
      cout<<"Queue empty!\n";
      return;
    }
    Node* current = front;
    while(current!=NULL)
    {
      cout<<current->data<<" ";
      current=current->next;
    }
    cout<<endl;
  }

  ~Queue()
  {
    Node* temp = NULL, *current = front;
    while(current!=NULL)
    {
      temp = current;
      current = current -> next;
      delete temp;
    }
  }
};