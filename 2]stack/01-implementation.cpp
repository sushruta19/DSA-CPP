/*Implementation of Stack(LIFO) By Singly Linked List*/

#include<iostream>
using namespace std;

class Node
{
  public:
  int data;
  Node* next;
  Node(int x=0):data{x},next{NULL}{}
};

class Stack
{
  public:
  Node* head;

  Stack():head{NULL}{}

  bool isEmpty()
  {
    return (head == NULL);
  }

  void push(int value)
  {
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
  }

  int pop()
  {
    if(this->isEmpty())
      throw underflow_error("Stack is Empty!\n");

    int popped = head->data;

    Node* temp = head;
    head = head->next;
    delete temp;
    
    return popped;
  }

  int peek()
  {
    if(this->isEmpty())
      throw underflow_error("Stack is Empty!\n");
    
    return head->data;
  }

  int size()
  {
    if(this->isEmpty())
    {
      return 0;
    }
    int len=0;
    Node* current = head;
    while(current!=NULL)
    {
      len++;
      current = current->next;
    }
    return len;
  }

  void showStack()
  {
    if(this->isEmpty())
    {
      cout<<"Stack is Empty\n";
      return;
    }
    Node* current = head;
    while(current!=NULL)
    {
      cout<<current->data << " ";
      current = current->next;
    }
    cout<<"\n";
  }

  ~Stack()
  {
    Node* temp=NULL, *current=head;
    while(current!=NULL)
    {
      temp = current;
      current = current->next;
      delete temp;
    }
  } 
};

//Driver Program
int main()
{
  Stack s;
  cout<<"Created an instance of class<Stack>\n";
  s.isEmpty()?cout<<"Stack is Empty!\n":cout<<"Stack is Full!\n";
  cout<<"\nPushing Elements in Stack\n";
  for(int i=1;i<=5;i++)
  {
    s.push(i*10);
  }
  cout<<"Top Element is: "<<s.peek()<<endl;
  cout<<"Size of Stack is: "<<s.size()<<endl;

  s.showStack();
}