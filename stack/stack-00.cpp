/*Implementation of Stack(LIFO) By Static Array*/

#include<iostream>
#include<stdexcept>
using namespace std;

class Stack
{
  public:
  int *a;
  int top, capacity;

  Stack(int cap)
  {
    top = -1;
    capacity = cap;
    a = new int[capacity];
  }
  
  bool isEmpty()
  {
    return (top == -1);
  }

  bool isFull()
  {
    return (top == capacity-1);
  }

  void push(int value)
  {
    if(this->isFull())
      throw overflow_error("Stack is overflowed\n");
    top++;
    a[top] = value;
  }

  int pop()
  {
    if(this->isEmpty())
      throw underflow_error("Stack is empty\n");
    top--;
    return a[top+1];
  }

  int peek()
  {
    if(this->isEmpty())
      throw underflow_error("Stack is empty\n");

    return a[top];
  }

  int size()
  {
    return top+1;
  }

  ~Stack()
  {
    delete[] a;
  }
};

void showStack(Stack s)
{
  while(!s.isEmpty())
  {
    cout<<s.peek()<<" ";
    s.pop();
  }
  cout<<"\n";
}

//Driver Program
int main()
{
  Stack s(5);
  cout<<"Created an instance of class<Stack> with capacity 5\n";

  s.isEmpty()?cout<<"Stack is Empty!\n":cout<<"Stack is Full!\n";

  cout<<"\nPushing Elements in Stack\n";
  for(int i=1;i<=5;i++)
  {
    s.push(i*10);
  }
  cout<<"Top Element is: "<<s.peek()<<endl;
  cout<<"Size of Stack is: "<<s.size()<<endl;

  showStack(s);
}
//couldn't locate memory leak in the above code