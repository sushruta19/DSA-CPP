#include "sll-0.cpp"
//The above source file "sll-0.cpp" contains the necessary header files and
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

/**************************Reverse linked list*********************************/

//Reverses the linked list
//Iterative
void reverseLinkedList(Node** head_ref)
{
  if(*head_ref == NULL || (*head_ref)->next == NULL)
    return;
  Node* prev = NULL, *next = NULL, *current = *head_ref;
  while(current!=NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head_ref = prev;
}

//Reverses the linked list
//Recursive
Node* reverseLinkedList2(Node* head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  else
  {
    Node* rest = reverseLinkedList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
  }
}



//Driver Code
int main()
{
  Node* head = NULL;
  for(int i=10;i>=1;i--)
  {
    push(&head,10*i);
  }
  printLinkedList(head);
  cout<<"Middle Element: "<<getMidLinkedList2(head) << endl;
  head = reverseLinkedList2(head);
  printLinkedList(head);
  deleteLinkedList2(head);
}