/*stack Standard Template Library*/

#include<iostream>
#include<stack>
using namespace std;

void showStack(stack<int> s)
{
  while(!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout<<endl;
}

int main()
{
  stack<int> s;

  s.empty()?cout<<"Stack is Empty!\n":cout<<"Stack is Full!\n";

  for(int i=1;i<=5;i++)
  {
    s.push(i*10);
  }
  cout<<"Top Element is: "<<s.top()<<endl;
  cout<<"Size of Stack is: "<<s.size()<<endl;

  showStack(s);

  stack<int> s2;
  s2.push(12);
  s2.push(13);
  s2.emplace(14); //almost same as push

  s2.swap(s);  //stacks can be swapped of varying length
}

/*
 *#include<stack>
 *Functions : empty(), push(int), emplace(int), pop(), top(), size(), swap(stack<int>)
*/