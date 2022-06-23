#include "00-implementation.cpp"
//The above source file "00-implementation.cpp" contains the necessary header files and
//implementation of singly linked list and 
//its basic operations(push, append, delete, print, search)

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