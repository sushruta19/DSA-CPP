#include "00-implementation.cpp"
//The above source file "00-implementation.cpp" contains the necessary header files and
//implementation of singly linked list and 
//its basic operations(push, append, delete, print, search) 
#include<vector>
using namespace std;

//function to check whether linked list is palindrome
//T:O(n) AS:O(n)
bool isPalindrome(Node* head)
{
  if(head == NULL)
    throw invalid_argument("Loop is Empty\n");
  Node* current = head;
  vector<int> num;
  while(current!=NULL)
  {
    num.push_back(current->data);
    current = current->next;
  }
  int n = num.size();
  int low = 0, high = n-1;
  while(low<high)
  {
    if(num[low]!=num[high])
      return false;
    low++;
    high--;
  }
  return true;
}

//Driver Program
int main()
{
  Node* head = NULL;
  append(&head, 1);
  append(&head, 2);
  append(&head, 3);
  append(&head, 1);
  isPalindrome(head)?cout<<"Yes a palindrome":cout<<"No";
  deleteLinkedList(&head);
}

