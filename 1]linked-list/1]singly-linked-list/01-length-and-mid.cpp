#include "00-implementation.cpp"
//The above source file "00-implementation.cpp" contains the necessary header files and
//implementation of singly linked list and 
//its basic operations(push, append, delete, print, search)

/************************Length of Singly Linked List************************/

//Finding length of linked list(using one pointer)
//iterative
int lengthLinkedList(Node* head)
{
  int len = 0;
  Node* current = head;
  while(current!=NULL)
  {
    len++;
    current=current->next;
  }
  return len;
}

//Finding length of linked list(using one pointer)
//recursive
int lengthLinkedListRecursive(Node* head)
{
  if(head == NULL)
    return 0;
  return 1 + lengthLinkedListRecursive(head->next);
}

/*********************Get Mid Element of Singly Linked List********************/
//We can find total length of linked list and then find the mid

//Another way is
//Finding mid Element of linked list by two pointers
int getMidLinkedList2(Node* head)
{
  if(head==NULL)
    return 0;
  Node* slow=head, *fast = head;
  while(fast->next!=NULL && fast->next->next!=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
}